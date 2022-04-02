/**
 * IZP First Project
 * Author: Mikhail Diachenko
 */

#include<stdio.h>
#include<stdlib.h>

/**
 * More information about functions you can see before the definition of functions
 */
int big_small_letter(char* string); //checking if password contains big and small letters
int number_symbol(char* string, int param); //checking if password contains numbers and symbols
int level_checker(char* string, int level, int param, int len); //checking a password security level
int length_of_string(char* string); //counting a length of string
int similar_symbols(char* string, int param, int len); //checking a length of substring of similar symbols
int similar_substrings(char* string, int param, int len); //checking a lenght of similar substrings
int stats_compare(char* string, char* stats);  //checking if "--stats" argument inputed


int main(int argc, char* argv[]){ //argc - number of arguments; argv - list of arguments
    int lvl, param; //'lvl' - required level of safety, 'param' - X param
    char* stats; //'stats' - required for cheking if  '--stats' is inputed
    if(argc < 3){
        printf("Calling Function Error: Please enter LEVEL and PARAM!\n");
        return EXIT_FAILURE;
    }
    lvl = atoi(argv[1]);
    param = atoi(argv[2]);
    stats = argv[3];
    char list[101]; //'list' - array for inputed string
    int min = 101, avg = 0, total = 0, different_symbols = 0; //'min' - length of the shortest password, 'avg' - average length of passwords, 'total' - number of passwords, 'different_symbols' - number of different symbols
    int symbols[127]; //'symbols' is an array, where indexes of elements means ASCII numbers of symbols
    while(fgets(list, 101, stdin) != NULL){ //'list' is in array, where fgets will put inputed string, '101' means maximum length (maximum could be 101-1 = 100), 'stdin' is a data stream
        int len = length_of_string(list);
        if(level_checker(list, lvl, param, len)){
            printf("%s", list);
        }
        /**
         * Next piece of code is for counting stats infromation. Program will print STATS in case of '--stats' argument is inputed
         */
        for(int i = 0; i < len; i++){
            int j = list[i];
            if(symbols[j] != 1){ //if symbols[j] != 1, than this symbol is found for the first time
                symbols[j] = 1;
                different_symbols++;
            }
        }
        if((len - 1) != 0){ //for the case of blank string at the end of the file
            if((len - 1) < min) min = len - 1; // -1 because of \n in the end of the string
            avg = avg + (len - 1); // -1 because of \n in the end of the string
            total++;
            }
        }
    if(total == 0){
        printf("Input Data Error: Please check that you have entered the passwords!\n"); //cheks if there are any passwords in the file
        return EXIT_FAILURE;
    }
    if(stats != NULL){
        if(stats_compare(stats, "--stats")){
            printf("Statistika:\n");
            printf("Ruznych znaku: %d\n", different_symbols  - 1); // -1 because of separator
            printf("Minimalni delka: %d\n", min);
            printf("Prumerna delka: %g\n", avg / (double)total);
        }
    }
    return 0;
}

/**
 * Function for counting a safety level of password
 * 'string' - current password
 * 'level' - required level of safety
 * 'param' - X value
 * 'len' - length of current password
 */

int level_checker(char* string, int level, int param, int len){
    if(big_small_letter(string)){
        if (level == 1) return 1; //if required level is 1 and in password there are at least 1 small and 1 big letters, it will return this password as target. If required level is not 1, it will check next levels
        else if(number_symbol(string, param)){
            if(level == 2) return 1;
            else if(similar_symbols(string, param, len)){
                if(level == 3) return 1;
                else if(similar_substrings(string, param, len)){
                    if(level == 4) return 1;
                }
            }
        }
    }

    return 0;
}

/**
 * Function for checking if program has an argument "--stats" inputed
 * 'string' - Third parameter
 * 'stats' - '--stats' string
 */

int stats_compare(char* string, char* stats){
    int i = 0;
     while(string[i]!='\0' || stats[i]!='\0'){ //It will check if both strings have the same length. So if inputed '--statsdasd' instead of '--stats' it will not show STATS
         if(string[i]!= stats[i]){
             return 0;
         }
         i++;
     }
     return 1;
}


/**
 * Function for checking if password contains at least 1 big and 1 small letters
 * 'string' - current password
 */

int big_small_letter(char* string){
    int i = 0, big = 0, small = 0; //'big' and 'small' are flags for big and small letters
    while(string[i] != '\0'){
            if(string[i] >= 'A' && string[i] <= 'Z') big = 1;
            else if(string[i] >= 'a' && string[i] <= 'z') small = 1;
            i++;
    }

    if(small + big == 2){
        return 1;
    }
    return 0;
}

/**
 * Function for checking if password contains big and small letters, numbers or symbols
 * 'string' - current password
 * 'param' - X value
 */

int number_symbol(char* string, int param){
    int i = 0, big = 0, small = 0, number = 0, symbol = 0; //'big', 'small', 'number', 'symbol' are flags for big and small letters, numbers and symbols
    while(string[i] != '\0'){
        if(string[i] >= 'A' && string[i] <= 'Z') big = 1;
        else if(string[i] >= 'a' && string[i] <= 'z') small = 1;
        else if(string[i] >= '0' && string[i] <= '9') number = 1;
        else if((string[i] >= 32 && string[i] <= 48) || (string[i] >= 58 && string[i] <= 64) || (string[i] >= 91 && string[i] <= 96) || (string[i] >= 123 && string[i] <= 126)) symbol = 1;
        i++;
    }

    if(big + small + number + symbol >= param){
        return 1;
    }
    else if(param > 4 && big + small + number + symbol == 4) return 1;
    return 0;
}

/**
 * Function for checking length of current password
 * 'string' - current password
 */

int length_of_string(char* string){
    int i = 0;
    while(string[i] != '\0'){
                i++;
    }
    return i;
}

/**
 * Function for checking if string contains a substring of similar symbols with length of at least X symbols
 * 'string' - current password
 * 'param' - X value
 * 'len' - length of current password
 */

int similar_symbols(char* string, int param, int len){
    int cnt = 0; //'cnt' requires to count the length of substring of similar symbols
    for(int i = 0; i < len - (param - 1); i++){ //this loop is for working with each character, which can be the beginning of a substring of single characters. So it is enough to check the string before (len - param + 1)
        for(int j = i; j < i + param; j++){
            if(string[i] == string[j]) cnt++; //here program s checking if the first symbol of substring equals to current.
        }
        if(cnt == param) return 0; //if this is a substring of single characters with a length of X, function returns 0
        cnt = 0;
    }
    return 1;
}

/**
 * Function for checking if string contains 2 similar substrings with length of at least X symbols
 * 'string' - current password
 * 'param' - X value
 * 'len' - length of current password
 */

int similar_substrings(char* string, int param, int len){  
    for(int i = 0; i < len - (param - 1); i++){
        for(int j = i + param; j < len; j++){
            int n = 0, cnt = 0; //'n' is necessary for comparing substrings by increasing n by 1 and checking if n element of the first substring == n element of the second substring, 'cnt' is for counting a number os single characters on the same positions
            while(n < param){
                if(string[i+n] == string[j+n]){
                    cnt++;
                }
                else break;
                n++;
            }
            if(cnt == param) return 0; //if number of single elements on the same positions in two substrings == X param, it means, that this to substrings a similar with the length of X, so the function will return 0
        }
    }

    return 1;
}
