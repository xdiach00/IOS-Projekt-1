#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALLOCATE_BASE_SIZE 16
#define MAX_ELEM_SIZE 30

typedef struct {
    char **elements;
    int size;
    int line;
} Set;

typedef struct {
    char *first;
    char *second;
} Pair;

typedef struct {
    Pair *pairs;
    int size;
    int line;
} Relation;

typedef struct {
    Set *sets; //Universe is on first index (0)
    int sets_size;
    Relation *relations;
    int relations_size;
} MainStructure;

/**
 * Function to realloc dynamically allocated array of strings
 * @param ptr pointer to array of strings
 * @param old_size old array items count
 * @param new_size new array items count
 * @return true if success false if failed
 */
bool reallocArrayOfStrings(char ***ptr, int old_size, int new_size) {
    char **new_ptr = (char **) realloc(*ptr, new_size * sizeof(char *));
    if (new_ptr == NULL) {
        return false;
    }
    for (int i = old_size; i < new_size; i++) {
        new_ptr[i] = NULL;
    }
    *ptr = new_ptr;
    return true;
}

/**
 * Function to realloc dynamically allocated array of Sets
 * @param set pointer to array of sets
 * @param old_size old array items count
 * @param new_size new array items count
 * @return true if success false if failed
 */
bool reallocSets(Set **set, int old_size, int new_size) {
    Set *new_ptr = (Set *) realloc(*set, new_size * sizeof(Set));
    if (new_ptr == NULL) {
        return false;
    }
    for (int i = old_size; i < new_size; i++) {
        new_ptr[i].elements = NULL;
        new_ptr[i].size = 0;
        new_ptr[i].line = 0;
    }
    *set = new_ptr;
    return true;
}

/**
 * Function to realloc dynamically allocated array of Pairs
 * @param pair pointer to array of pairs
 * @param old_size old array items count
 * @param new_size new array items count
 * @return true if success false if failed
 */
bool reallocPairs(Pair **pair, int old_size, int new_size) {
    Pair *new_ptr = (Pair *) realloc(*pair, new_size * sizeof(Pair));
    if (new_ptr == NULL) {
        return false;
    }
    for (int i = old_size; i < new_size; i++) {
        new_ptr[i].first = NULL;
        new_ptr[i].second = NULL;
    }
    *pair = new_ptr;
    return true;
}

/**
 * Function to realloc dynamically allocated array of relations
 * @param relation pointer to array of relations
 * @param old_size old array items count
 * @param new_size new array items count
 * @return true if success false if failed
 */
bool reallocRelations(Relation **relation, int old_size, int new_size) {
    Relation *new_ptr = (Relation *) realloc(*relation, new_size * sizeof(Relation));
    if (new_ptr == NULL) {
        return false;
    }
    for (int i = old_size; i < new_size; i++) {
        new_ptr[i].pairs = NULL;
        new_ptr[i].size = 0;
        new_ptr[i].line = 0;
    }
    *relation = new_ptr;
    return true;
}

/**
 * Initialize Set
 * @param set pointer to set to initialize
 * @return true if success false if failed
 */
bool setInit(Set *set) {
    char **ptr = (char **) calloc(ALLOCATE_BASE_SIZE, sizeof(char *));
    if (ptr == NULL) {
        return false;
    }
    set->elements = ptr;
    set->size = ALLOCATE_BASE_SIZE;
    return true;
}

/**
 * Initialize relation
 * @param relation pointer to relation to initialize
 * @return true if success false if failed
 */
bool relationInit(Relation *relation) {
    Pair *ptr = (Pair *) calloc(ALLOCATE_BASE_SIZE, sizeof(Pair));
    if (ptr == NULL) {
        return false;
    }
    relation->pairs = ptr;
    relation->size = ALLOCATE_BASE_SIZE;
    return true;
}

/**
 * Function to free dynamically allocated array of strings
 * @param universe pointer to array
 * @param size size of array
 */
void freeUniverse(char **universe, int size) {
    for (int i = 0; i < size && universe[i] != NULL; i++) {
        free(universe[i]);
    }
    free(universe);
}

/**
 * Function to free dynamically allocated array of relations
 * @param relations pointer to relations array
 * @param size size of array
 */
void freeRelations(Relation *relations, int size) {
    for (int i = 0; i < size && relations[i].pairs != NULL; i++) {
        free(relations[i].pairs);
    }
    free(relations);
}

/**
 * Function to free dynamically allocated array of sets
 * @param sets pointer to relations array
 * @param size size of array
 */
void freeSets(Set *sets, int size) {
    for (int i = 1; i < size && sets[i].elements != NULL; i++) {
        free(sets[i].elements);
    }
    free(sets);
}

/**
 * Function to free main structure
 * @param mainStructure pointer to relations array
 */
void freeMainStructure(MainStructure *structure) {
    freeUniverse(structure->sets[0].elements, structure->sets[0].size);
    freeSets(structure->sets, structure->sets_size);
    freeRelations(structure->relations, structure->relations_size);
}

/**
 * Function to initialize main structure
 * @param structure main structure to initialize
 * @return true if success fail if failed
 */
bool mainStructureAllocate(MainStructure *structure) {
    structure->sets = (Set *) calloc(ALLOCATE_BASE_SIZE, sizeof(Set));
    if (structure->sets == NULL) {
        freeMainStructure(structure);
        return false;
    }
    structure->sets_size = ALLOCATE_BASE_SIZE;
    structure->relations = (Relation *) calloc(ALLOCATE_BASE_SIZE, sizeof(Relation));
    if (structure->relations == NULL) {
        freeMainStructure(structure);
        return false;
    }
    structure->relations_size = ALLOCATE_BASE_SIZE;
    return true;
}

/**
 * Function prints Universe and all sets
 * @param mainStructure main structure with Sets
 */
void printSets(MainStructure *mainStructure) {
    printf("U");
    for (int i = 0; i < mainStructure->sets[0].size && mainStructure->sets[0].elements[i] != NULL; i++) {
        printf(" %s", mainStructure->sets[0].elements[i]);
    }
    printf("\n");
    for (int y = 1; y < mainStructure->sets_size && mainStructure->sets[y].elements != NULL; y++) {
        printf("S");
        for (int i = 0; i < mainStructure->sets[y].size && mainStructure->sets[y].elements[i] != NULL; i++) {
            printf(" %s", mainStructure->sets[y].elements[i]);
        }
        printf("\n");
    }
}

/**
 * Function prints all relations in main structure
 * @param mainStructure main structure with relations
 */
void printRelations(MainStructure *mainStructure) {
    for (int y = 0; y < mainStructure->relations_size && mainStructure->relations[y].pairs != NULL; y++) {
        printf("R");
        for (int i = 0;
             i < mainStructure->relations[y].size && mainStructure->relations[y].pairs[i].first != NULL; i++) {
            printf(" (%s %s)", mainStructure->relations[y].pairs[i].first,
                   mainStructure->relations[y].pairs[i].second);
        }
        printf("\n");
    }
}

/**
 * Function prints if set is empty or not.
 * @param set set to be check
 */
void emptySet(Set *set) {
    if (set->size > 0 && set->elements[0] != NULL) {
        printf("false\n");
        return;
    }
    printf("true\n");
}

/**
 * Function prints number of elements in set.
 * @param set set to be count
 */
void cardSet(Set *set) {
    int i = 0;
    while (i < set->size && set->elements[i] != NULL) {
        i++;
    }
    printf("%d\n", i);
}

/**
 * Function prints complement of current set.
 * @param set set to count complement
 * @param universe universe to check complement
 */
void complementSet(Set *set, Set *universe) {
    printf("S");
    bool flag;
    for (int i = 0; i < universe->size; i++) {
        if (universe->elements[i] != NULL) {
            flag = false;
            int j = 0;
            while (set->elements[j] != NULL) {
                if (strcmp(universe->elements[i], set->elements[j]) == 0) {
                    flag = true;
                    break;
                }
                j++;
            }
            if (!flag) {
                printf(" %s", universe->elements[i]);
            }
        }
    }
    printf("\n");
}

/**
 * Function prints union of two sets.
 * @param setA first set of union
 * @param setB second set of union
 */
void unionSet(Set *setA, Set *setB) {
    printf("S");
    int i = 0;
    while (i < setA->size && setA->elements[i] != NULL) {
        printf(" %s", setA->elements[i]);
        i++;
    }
    i = 0;
    while (i < setB->size && setB->elements[i] != NULL) {
        int j = 0;
        bool flag = 0;
        while (setA->elements[j] != NULL && j < setA->size) {
            if (strcmp(setB->elements[i], setA->elements[j]) == 0) {
                flag = true;
                break;
            }
            j++;
        }
        if (!flag) printf(" %s", setB->elements[i]);
        i++;
    }
    printf("\n");
}

/**
 * Function prints intersect of two sets.
 * @param setA first set of intersect
 * @param setB second set of intersect
 */
void intersectSet(Set *setA, Set *setB) {
    printf("S");
    int i = 0;
    while (i < setA->size && setA->elements[i] != NULL) {
        int j = 0;
        bool flag = 0;
        while (j < setB->size && setB->elements[j] != NULL) {
            if (strcmp(setA->elements[i], setB->elements[j]) == 0) {
                flag = true;
                break;
            }
            j++;
        }
        if (flag) printf(" %s", setA->elements[i]);
        i++;
    }
    printf("\n");
}

/**
 * Function to print the difference between two sets.
 * @param setA first set of minus
 * @param setB second set of minus
 */
void minusSet(Set *setA, Set *setB) {
    printf("S");
    int i = 0;
    while (i < setA->size && setA->elements[i] != NULL) {
        int j = 0;
        bool flag = 0;
        while (j < setB->size && setB->elements[j] != NULL) {
            if (strcmp(setA->elements[i], setB->elements[j]) == 0) {
                flag = true;
                break;
            }
            j++;
        }
        if (!flag) printf(" %s", setA->elements[i]);
        i++;
    }
    printf("\n");
}

/**
 * Function checks if setA is a subset or equivalent of setB or not.
 * @param setA set to be checked if is subset
 * @param setB set which is superset
 */
void subseteqSet(Set *setA, Set *setB) {
    int i = 0, cnt = 0;
    while (i < setA->size && setA->elements[i] != NULL) {
        int j = 0;
        while (j < setB->size && setB->elements[j] != NULL) {
            if (strcmp(setA->elements[i], setB->elements[j]) == 0) {
                cnt++;
                break;
            }
            j++;
        }
        i++;
    }
    if (cnt == i) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

/**
 * Function checks if setA is a strict subset of setB or not.
 * @param setA set which should be subset
 * @param setB set which is superset
 */
void subsetSet(Set *setA, Set *setB) {
    if (setA->elements[0] == NULL && setB->elements[0] != NULL) {
        printf("true\n");
        return;
    }
    int i = 0, cnt = 0;
    while (i < setA->size && setA->elements[i] != NULL) {
        int j = 0;
        while (j < setB->size && setB->elements[j] != NULL) {
            if (strcmp(setA->elements[i], setB->elements[j]) == 0) {
                cnt++;
                break;
            }
            j++;
        }
        i++;
    }
    if (setB->elements[i] != NULL && i > 0 && cnt == i) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

/**
 * Function checks if setA is equal to setB.
 * @param setA first set to check
 * @param setB second set to check
 */
void equalsSet(Set *setA, Set *setB) {
    int i = 0, cnt = 0;
    while (i < setA->size && setA->elements[i] != NULL) {
        int j = 0;
        while (j < setB->size && setB->elements[j] != NULL) {
            if (strcmp(setA->elements[i], setB->elements[j]) == 0) {
                cnt++;
                break;
            }
            j++;
        }
        i++;
    }
    if (setB->elements[i] == NULL && cnt == i) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

/**
 * Function checks if current relation is reflexive or not.
 * @param relation relation to check
 * @param universe universe of relation elements
 */
void reflexiveRelation(Relation *relation, Set *universe) {
    int cnt = 0;
    int i = 0;
    while (i < universe->size && universe->elements[i] != NULL) {
        int j = 0;
        while (j < relation->size && relation->pairs[j].first != NULL) {
            if (strcmp(relation->pairs[j].first, universe->elements[i]) == 0 &&
                strcmp(relation->pairs[j].second, universe->elements[i]) == 0) {
                cnt++;
                break;
            }
            j++;
        }
        i++;
    }
    if (cnt == i) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

/**
 * Function checks if current relation is symmetric or not.
 * @param relation relation to check
 */
void symmetricRelation(Relation *relation) {
    int i = 0;
    while (i < relation->size && relation->pairs[i].first != NULL) {
        bool found = 0;
        int j = 0;
        while (j < relation->size && relation->pairs[j].first != NULL) {
            if (strcmp(relation->pairs[i].second, relation->pairs[j].first) == 0 &&
                strcmp(relation->pairs[i].first, relation->pairs[j].second) == 0) {
                found = 1;
                break;
            }
            j++;
        }
        i++;
        if (!found) {
            printf("false\n");
            return;
        }
    }
    printf("true\n");
}

/**
 * Function checks if current relation is antisymmetric or not.
 * @param relation relation to check
 */
void antisymmetricRelation(Relation *relation) {
    int i = 0;
    while (i < relation->size && relation->pairs[i].first != NULL) {
        bool found_wrong = 0;
        int j = 0;
        while (j < relation->size && relation->pairs[j].first != NULL) {
            if (strcmp(relation->pairs[i].second, relation->pairs[j].first) == 0 &&
                strcmp(relation->pairs[i].first, relation->pairs[j].second) == 0 &&
                strcmp(relation->pairs[i].first, relation->pairs[i].second) != 0) {
                found_wrong = 1;
                break;
            }
            j++;
        }
        i++;
        if (found_wrong) {
            printf("false\n");
            return;
        }
    }
    printf("true\n");
}

/**
 * Function checks if current relation is transitive or not.
 * @param relation relation to check
 */
void transitiveRelation(Relation *relation) {
    int i = 0;
    while (i < relation->size && relation->pairs[i].first != NULL) {
        int j = 0;
        while (j < relation->size && relation->pairs[j].first != NULL) {
            if (strcmp(relation->pairs[i].second, relation->pairs[j].first) == 0) {
                bool found = 0;
                int k = 0;
                while (k < relation->size && relation->pairs[k].first != NULL) {
                    if (strcmp(relation->pairs[i].first, relation->pairs[k].first) == 0 &&
                        strcmp(relation->pairs[j].second, relation->pairs[k].second) == 0) {
                        found = 1;
                        break;
                    }
                    k++;
                }
                if (!found) {
                    printf("false\n");
                    return;
                }
            }
            j++;
        }
        i++;
    }
    printf("true\n");
}

/**
 * Function checks if current relation is a function
 * @param relation relation to check
 * @return true if relation is function, false if not
 */
bool checkFunctionRelation(Relation *relation) {
    int i = 0;
    bool flag = 0;
    while (i < relation->size && relation->pairs[i].first != NULL) {
        int j = i;
        while (j < relation->size && relation->pairs[j].first != NULL) {
            if (strcmp(relation->pairs[i].first, relation->pairs[j].first) == 0 &&
                strcmp(relation->pairs[i].second, relation->pairs[j].second) != 0) {
                flag = 1;
                break;
            }
            j++;
        }
        if (flag) {
            break;
        }
        i++;
    }
    if (!flag) {
        return true;
    }
    return false;
}

/**
 * Function prints true if current relation is a function or false if it is not.
 * @param relation relation to check
 */
void functionRelation(Relation *relation) {
    if (checkFunctionRelation(relation)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

/**
 * Function prints domain of current relation.
 * @param relation relation to print domain
 */
void domainRelation(Relation *relation) {
    printf("S");
    int i = 0;
    while (i < relation->size && relation->pairs[i].first != NULL) {
        bool flag = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(relation->pairs[i].first, relation->pairs[j].first) == 0) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            printf(" %s", relation->pairs[i].first);
        }
        i++;
    }
    printf("\n");
}

/**
 * Function prints codomain of current relation.
 * @param relation relation to print codomain
 */
void codomainRelation(Relation *relation) {
    printf("S");
    int i = 0;
    while (i < relation->size && relation->pairs[i].first != NULL) {
        bool flag = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(relation->pairs[i].second, relation->pairs[j].second) == 0) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            printf(" %s", relation->pairs[i].second);
        }
        i++;
    }
    printf("\n");
}

/**
 * Function checks if elements of current relation are in sets A and B.
 * @param relation relation to check
 * @param aSet Set of first element of each pair
 * @param bSet Set of second element of each pair
 * @return true if elements of current relation are in sets A and B or false if not
 */
bool elementsInSets(Relation *relation, Set *aSet, Set *bSet){
    int i = 0;
    bool flag = 0;
    while (i < relation->size && relation->pairs[i].first != NULL) {
        int k = 0;
        while (k < aSet->size && aSet->elements[k] != NULL) {
            if (strcmp(relation->pairs[i].first, aSet->elements[k]) != 0) {
                flag = 1;
            } else {
                flag = 0;
                break;
            }
            k++;
        }
        if (flag) {
            return false;
        }
        k = 0;
        while (k < bSet->size && bSet->elements[k] != NULL) {
            if (strcmp(relation->pairs[i].second, bSet->elements[k]) != 0) {
                flag = 1;
            } else {
                flag = 0;
                break;
            }
            k++;
        }
        if (flag) {
            return false;
        }
        i++;
    }
    return true;
}

/**
 * Function checks if current relation is injective or not.
 * @param relation relation to check
 * @param aSet Set of first element of each pair
 * @param bSet Set of second element of each pair
 */
void injectiveRelation(Relation *relation, Set *aSet, Set *bSet) {
    int i = 0;
    bool flag = 0;
    if ((aSet->elements[0] == NULL || bSet->elements[0] == NULL) && relation->pairs[0].first != NULL) {
        printf("false\n");
        return;
    }
    if (!checkFunctionRelation(relation)) {
        printf("false\n");
        return;
    }
    if (!elementsInSets(relation, aSet, bSet)){
        printf("false\n");
        return;
    }
    while (i < relation->size && relation->pairs[i].first != NULL) {
        for (int j = 0; j < i; j++) {
            if (strcmp(relation->pairs[i].first, relation->pairs[j].first) == 0 ||
                strcmp(relation->pairs[i].second, relation->pairs[j].second) == 0) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            break;
        }
        i++;
    }
    int k = 0;
    while (k < aSet->size && aSet->elements[k] != NULL) {
        k++;
    }
    if (!flag && k == i) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

/**
 * Function checks if current relation is surjective or not.
 * @param relation relation to check
 * @param aSet Set of first element of each pair
 * @param bSet Set of second element of each pair
 */
void surjectiveRelation(Relation *relation, Set *aSet, Set *bSet) {
    int i = 0, cnt = 0;
    if ((aSet->elements[0] == NULL || bSet->elements[0] == NULL) && relation->pairs[0].first != NULL) {
        printf("false\n");
        return;
    }
    if (!checkFunctionRelation(relation)) {
        printf("false\n");
        return;
    }
    if (!elementsInSets(relation, aSet, bSet)) {
        printf("false\n");
        return;
    }
    while (i < bSet->size && bSet->elements[i] != NULL) {
        int j = 0;
        while (j < relation->size && relation->pairs[j].first != NULL) {
            if (strcmp(bSet->elements[i], relation->pairs[j].second) == 0) {
                cnt++;
                break;
            }
            j++;
        }
        i++;
    }
    if (cnt == i) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

/**
 * Function checks if current function is bijective or not.
 * @param relation relation to check
 * @param aSet Set of first element of each pair
 * @param bSet Set of second element of each pair
 */
void bijectiveRelation(Relation *relation, Set *aSet, Set *bSet) {
    int i = 0, cnt = 0;
    bool flag = 0;
    if ((aSet->elements[0] == NULL || bSet->elements[0] == NULL) && relation->pairs[0].first != NULL) {
        printf("false\n");
        return;
    }
     if (!checkFunctionRelation(relation)) {
        printf("false\n");
        return;
    }
    if (!elementsInSets(relation, aSet, bSet)){
        printf("false\n");
        return;
    }
    while (i < relation->size && relation->pairs[i].first != NULL) {
        int j = i;
        while (j < relation->size && relation->pairs[j].first != NULL) {
            if ((strcmp(relation->pairs[i].first, relation->pairs[j].first) == 0 &&
                 strcmp(relation->pairs[i].second, relation->pairs[j].second) != 0) ||
                (strcmp(relation->pairs[i].second, relation->pairs[j].second) == 0 &&
                 i != j)) {
                flag = 1;
                break;
            }
            j++;
        }
        if (flag) {
            break;
        }
        i++;
    }
    if (flag) {
        printf("false\n");
        return;
    }
    flag = 0;
    i = 0;
    while (i < bSet->size && bSet->elements[i] != NULL) {
        int j = 0;
        while (j < relation->size && relation->pairs[j].first != NULL) {
            if (strcmp(bSet->elements[i], relation->pairs[j].second) == 0) {
                cnt++;
            }
            j++;
        }
        i++;
    }

    if (cnt == i) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

/**
 * Function returns Set found by line
 * @param mainStructure main structure with sets
 * @param line line of set to be found
 * @return NULL if doesnt exist, Set if found
 */
Set *getSetByLine(MainStructure *mainStructure, int line) {
    for (int i = 0; i < mainStructure->sets_size && mainStructure->sets[i].elements != NULL; i++) {
        if (mainStructure->sets[i].line == line) {
            return &mainStructure->sets[i];
        }
    }
    return NULL;
}

/**
 * Function returns Relation found by line
 * @param mainStructure main structure with relations
 * @param line line of relation to be found
 * @return NULL if doesnt exist, Relation if found
 */
Relation *getRelationByLine(MainStructure *mainStructure, int line) {
    for (int i = 0; i < mainStructure->relations_size && mainStructure->relations[i].pairs != NULL; i++) {
        if (mainStructure->relations[i].line == line) {
            return &mainStructure->relations[i];
        }
    }
    return NULL;
}

/**
 * Function calls empty function on Set found by line
 * @param mainStructure main structure with sets
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callEmpty(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 1) {
        return false;
    }
    Set *firstSet = getSetByLine(mainStructure, lines[0]);
    if (firstSet == NULL) {
        return false;
    }
    emptySet(firstSet);
    return true;
}

/**
 * Function calls card function on Set found by line
 * @param mainStructure main structure with sets
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callCard(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 1) {
        return false;
    }
    Set *firstSet = getSetByLine(mainStructure, lines[0]);
    if (firstSet == NULL) {
        return false;
    }
    cardSet(firstSet);
    return true;
}

/**
 * Function calls complement function on Set found by line
 * @param mainStructure main structure with sets
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callComplement(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 1) {
        return false;
    }
    Set *firstSet = getSetByLine(mainStructure, lines[0]);
    if (firstSet == NULL) {
        return false;
    }
    complementSet(firstSet, &mainStructure->sets[0]);
    return true;
}

/**
 * Function calls Union function on two Sets found by line
 * @param mainStructure main structure with sets
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callUnion(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 2) {
        return false;
    }
    Set *firstSet = getSetByLine(mainStructure, lines[0]);
    Set *secondSet = getSetByLine(mainStructure, lines[1]);
    if (firstSet == NULL || secondSet == NULL) {
        return false;
    }
    unionSet(firstSet, secondSet);
    return true;
}

/**
 * Function calls Intersect function on two sets found by line
 * @param mainStructure main structure with sets
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callIntersect(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 2) {
        return false;
    }
    Set *firstSet = getSetByLine(mainStructure, lines[0]);
    Set *secondSet = getSetByLine(mainStructure, lines[1]);
    if (firstSet == NULL || secondSet == NULL) {
        return false;
    }
    intersectSet(firstSet, secondSet);
    return true;
}

/**
 * Function calls Minus function on two sets found by line
 * @param mainStructure main structure with sets
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callMinus(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 2) {
        return false;
    }
    Set *firstSet = getSetByLine(mainStructure, lines[0]);
    Set *secondSet = getSetByLine(mainStructure, lines[1]);
    if (firstSet == NULL || secondSet == NULL) {
        return false;
    }
    minusSet(firstSet, secondSet);
    return true;
}

/**
 * Function calls SubsetEq function on two sets found by line
 * @param mainStructure main structure with sets
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callSubsetEq(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 2) {
        fprintf(stderr, "invalid lines count");
        return false;
    }
    Set *firstSet = getSetByLine(mainStructure, lines[0]);
    Set *secondSet = getSetByLine(mainStructure, lines[1]);
    if (firstSet == NULL || secondSet == NULL) {
        return false;
    }
    subseteqSet(firstSet, secondSet);
    return true;
}

/**
 * Function calls Subset function on two sets found by line
 * @param mainStructure main structure with sets
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callSubset(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 2) {
        return false;
    }
    Set *firstSet = getSetByLine(mainStructure, lines[0]);
    Set *secondSet = getSetByLine(mainStructure, lines[1]);
    if (firstSet == NULL || secondSet == NULL) {
        return false;
    }
    subsetSet(firstSet, secondSet);
    return true;
}

/**
 * Function calls Equals function on two sets found by line
 * @param mainStructure main structure with sets
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callEquals(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 2) {
        fprintf(stderr, "invalid lines count");
        return false;
    }
    Set *firstSet = getSetByLine(mainStructure, lines[0]);
    Set *secondSet = getSetByLine(mainStructure, lines[1]);
    if (firstSet == NULL || secondSet == NULL) {
        fprintf(stderr, "invalid lines");
        return false;
    }
    equalsSet(firstSet, secondSet);
    return true;
}

/**
 * Function calls Reflexive function on relation found by line
 * @param mainStructure main structure with relations
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callReflexive(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 1) {
        return false;
    }
    Relation *firstRelation = getRelationByLine(mainStructure, lines[0]);
    if (firstRelation == NULL) {
        return false;
    }
    reflexiveRelation(firstRelation, &mainStructure->sets[0]);
    return true;
}

/**
 * Function calls Symetric function on relation found by line
 * @param mainStructure main structure with relations
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callSymmetric(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 1) {
        return false;
    }
    Relation *firstRelation = getRelationByLine(mainStructure, lines[0]);
    if (firstRelation == NULL) {
        return false;
    }
    symmetricRelation(firstRelation);
    return true;
}

/**
 * Function calls Antisymetric function on relation found by line
 * @param mainStructure main structure with relations
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callAntisymmetric(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 1) {
        return false;
    }
    Relation *firstRelation = getRelationByLine(mainStructure, lines[0]);
    if (firstRelation == NULL) {
        return false;
    }
    antisymmetricRelation(firstRelation);
    return true;
}

/**
 * Function calls Transitive function on relation found by line
 * @param mainStructure main structure with relations
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callTransitive(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 1) {
        return false;
    }
    Relation *firstRelation = getRelationByLine(mainStructure, lines[0]);
    if (firstRelation == NULL) {
        return false;
    }
    transitiveRelation(firstRelation);
    return true;
}

/**
 * Function calls Function function on relation found by line
 * @param mainStructure main structure with relations
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callFunctionRelation(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 1) {
        return false;
    }
    Relation *firstRelation = getRelationByLine(mainStructure, lines[0]);
    if (firstRelation == NULL) {
        return false;
    }
    functionRelation(firstRelation);
    return true;
}

/**
 * Function calls Domain function on relation found by line
 * @param mainStructure main structure with relations
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callDomain(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 1) {
        return false;
    }
    Relation *firstRelation = getRelationByLine(mainStructure, lines[0]);
    if (firstRelation == NULL) {
        return false;
    }
    domainRelation(firstRelation);
    return true;
}

/**
 * Function calls Codomain function on relation found by line
 * @param mainStructure main structure with relations
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callCoDomain(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 1) {
        return false;
    }
    Relation *firstRelation = getRelationByLine(mainStructure, lines[0]);
    if (firstRelation == NULL) {
        return false;
    }
    codomainRelation(firstRelation);
    return true;
}

/**
 * Function calls Injective function on relation and two sets found by line
 * @param mainStructure main structure with relations and sets
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callInjective(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 3) {
        return false;
    }
    Relation *firstRelation = getRelationByLine(mainStructure, lines[0]);
    Set *firstSet = getSetByLine(mainStructure, lines[1]);
    Set *secondSet = getSetByLine(mainStructure, lines[2]);
    if (firstRelation == NULL || firstSet == NULL || secondSet == NULL) {
        return false;
    }
    injectiveRelation(firstRelation, firstSet, secondSet);
    return true;
}

/**
 * Function calls Surjective function on relation and two sets found by line
 * @param mainStructure main structure with relations and sets
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callSurjective(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 3) {
        return false;
    }
    Relation *firstRelation = getRelationByLine(mainStructure, lines[0]);
    Set *firstSet = getSetByLine(mainStructure, lines[1]);
    Set *secondSet = getSetByLine(mainStructure, lines[2]);
    if (firstRelation == NULL || firstSet == NULL || secondSet == NULL) {
        return false;
    }
    surjectiveRelation(firstRelation, firstSet, secondSet);
    return true;
}

/**
 * Function calls Bijective function on relation and two sets found by line
 * @param mainStructure main structure with relations and sets
 * @param lines command arguments
 * @param linesCount lines array size
 * @return true if called false if failed
 */
bool callBijective(MainStructure *mainStructure, int lines[], int linesCount) {
    if (linesCount != 3) {
        return false;
    }
    Relation *firstRelation = getRelationByLine(mainStructure, lines[0]);
    Set *firstSet = getSetByLine(mainStructure, lines[1]);
    Set *secondSet = getSetByLine(mainStructure, lines[2]);
    if (firstRelation == NULL || firstSet == NULL || secondSet == NULL) {
        return false;
    }
    bijectiveRelation(firstRelation, firstSet, secondSet);
    return true;
}

/**
 * Function calls Command function by name
 * @param funcName name of command function to be called
 * @param mainStructure main structure with sets and relations
 * @param lines arguments of command (lines of relations and sets)
 * @param linesCount lines array size
 * @return True if successfully called, Flase if failed
 */
bool callFunctions(char *funcName, MainStructure *mainStructure, int lines[], int linesCount) {
    if (strcmp(funcName, "empty") == 0) {
        return callEmpty(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "card") == 0) {
        return callCard(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "complement") == 0) {
        return callComplement(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "union") == 0) {
        return callUnion(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "intersect") == 0) {
        return callIntersect(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "minus") == 0) {
        return callMinus(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "subseteq") == 0) {
        return callSubsetEq(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "subset") == 0) {
        return callSubset(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "equals") == 0) {
        return callEquals(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "reflexive") == 0) {
        return callReflexive(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "symmetric") == 0) {
        return callSymmetric(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "antisymmetric") == 0) {
        return callAntisymmetric(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "transitive") == 0) {
        return callTransitive(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "function") == 0) {
        return callFunctionRelation(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "domain") == 0) {
        return callDomain(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "codomain") == 0) {
        return callCoDomain(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "injective") == 0) {
        return callInjective(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "surjective") == 0) {
        return callSurjective(mainStructure, lines, linesCount);
    }
    if (strcmp(funcName, "bijective") == 0) {
        return callBijective(mainStructure, lines, linesCount);
    }
    return false;

}

/**
 * Function reads two words between spaces from file
 * @param file file to be read
 * @param buffer buffer to save word
 * @param maxChars max count of characters to read
 * @return 0 FOR EOF
 *         1 FOR END OF LINE
 *         2 FOR SPACE
 *         -1 FOR INVALID LEN
 */
int readWord(FILE *file, char *buffer, int maxChars) {
    buffer[0] = '\0';
    int buffer_index = 0;
    while (true) {
        int c = fgetc(file);
        if (c == ' ') {
            continue;
        }
        if (c == EOF) {
            return 1;
        }
        fseek(file, -1, SEEK_CUR);
        break;
    }
    while (true) {
        int c = fgetc(file);
        if (c == EOF) {
            buffer[buffer_index] = '\0';
            return 0;
        }
        if (c == '\n') {
            buffer[buffer_index] = '\0';
            return 1;
        }
        if (c == ' ') {
            buffer[buffer_index] = '\0';
            return 2;
        }
        if (buffer_index == maxChars) {
            return -1;
        }
        buffer[buffer_index] = (char) c;
        buffer_index++;
    }
}

/**
 * Check if string contains only numbers
 * @param lineNumber string to be checked
 * @return true if string contains only numbers, false if not
 */
bool checkLineNumber(char *lineNumber) {
    for (int i = 0; lineNumber[i] != '\0'; i++) {
        if ((lineNumber[i] < '0' || lineNumber[i] > '9')) {
            return false;
        }
    }
    return true;
}
/**
 * Check if element contain only letters, for relation there are also ( and ) characters
 * @param element string to be checked
 * @param relation check if string is set or relaiton
 * @return true if string contains only allowed characters, false if not
 */
bool checkElementCharacters(char *element, bool relation) {
    for (int i = 0; element[i] != '\0'; i++) {
        if (relation && (element[i] < 'a' || element[i] > 'z') && (element[i] < 'A' || element[i] > 'Z') &&
            element[i] != '(' && element[i] != ')') {
            return false;
        }
        if (!relation && (element[i] < 'a' || element[i] > 'z') && (element[i] < 'A' || element[i] > 'Z')) {
            return false;
        }
    }
    return true;
}

/**
 * Check if element does not match unallowed word
 * @param element element to be checked
 * @return true if doesnt match, false if match
 */
bool checkElementUnallowedWords(char *element) {
    char *unallowed[] = {
            "true", "false", "empty", "card", "complement", "union", "intersect", "minus",
            "subseteq", "subset", "equals", "reflexive", "symmetric", "antisymmetric", "transitive",
            "function", "domain", "codomain", "injective", "surjective", "bijective"
    };
    for (int i = 0; i < 21; i++) {
        if (strcmp(element, unallowed[i]) == 0) {
            return false;
        }
    }
    return true;
}

/**
 * Get index of element in universe set
 * @param element element to be found
 * @param mainStructure main structure with sets and relations
 * @return -1 if not found or index of element in universe
 */
int getElementUniverseIndex(char *element, MainStructure* mainStructure) {
    for (int universe_index = 0; universe_index < mainStructure->sets[0].size &&
                                 mainStructure->sets[0].elements[universe_index] != NULL; universe_index++) {
        if (strcmp(element, mainStructure->sets[0].elements[universe_index]) == 0) {
            return universe_index;
        }
    }
    return -1;
}

/**
 * Check if is valid element
 * @param element element to check
 * @param mainStructure main structure with sets and relations
 * @param new_set new_created set
 * @return false if invalid, true if valid
 */
bool checkElement(char* element, Set *new_set) {
    if (!checkElementCharacters(element, false)) {
        fprintf(stderr, "UNIVERSE ELEMENT CONTAIN UNALOWED CHARACTER\n");
        return false;
    }
    if (!checkElementUnallowedWords(element)) {
        fprintf(stderr, "UNIVERSE ELEMENT CONTAIN UNALOWED CHARACTER\n");
        return false;
    }
    for (int i = 0; i < new_set->size && new_set->elements[i] != NULL; i++) {
        if (strcmp(element, new_set->elements[i]) == 0) {
            fprintf(stderr, "SET INVALID SET, TWO SAME ELEMENTS\n");
            return false;
        }
    }
    return true;
}

/**
 * Free newly allocated Set, if it is universe, freeUniverse is called
 * @param new_set set to free
 * @param universe true if set is universe
 */
void freeNewSet(Set *new_set, bool universe) {
    if (universe) {
        freeUniverse(new_set->elements, new_set->size);
    } else {
        free(new_set->elements);
    }
}

/**
 * Function read command from line and call functions over sets and relations
 * @param mainStructure main structure with sets and relations
 * @param file file to be read
 * @return true if successfully called function, false if failed
 */
bool readCommands(MainStructure *mainStructure, FILE *file) {
    char buffer[MAX_ELEM_SIZE + 1];
    int result = readWord(file, buffer, MAX_ELEM_SIZE);
    int linesArray[3];
    int lines_array_index = 0;
    if (result != 2) {
        fprintf(stderr, "INVALID COMMAND LEN\n");
        return false;
    }
    char command[MAX_ELEM_SIZE + 1];
    strcpy(command, buffer);

    while (true) {
        result = readWord(file, buffer, 4);
        if (result == -1) {
            fprintf(stderr, "COMMAND INVALID LINE NUMBER LEN \n");
            return false;
        }
        if (!checkLineNumber(buffer)) {
            fprintf(stderr, "COMMAND LINE NUMBER CONTAIN UNALLOWED CHARACTERS\n");
            return false;
        }
        if (strlen(buffer) != 0) {
            int num = (int) strtol(buffer, (char **) NULL, 10);
            if (lines_array_index == 3) {
                fprintf(stderr, "COMMAND INVALID LINES COUNT\n");
                return false;
            }
            linesArray[lines_array_index] = num;
            lines_array_index++;
        }
        if (result == 0 || result == 1) {
            break;
        }
    }
    if (!callFunctions(command, mainStructure, linesArray, lines_array_index)) {
        fprintf(stderr, "COMMAND: %s INVALID FUNCTION CALL\n", command);
        return false;
    }
    return true;
}

/**
 * Function find free index in sets array in main structure, if array is fully filled, function reallocate array
 * @param mainStructure main structure with sets and relations
 * @return -1 if reallocate failed or found index
 */
int findSetFreeIndex(MainStructure *mainStructure) {
    int freeSetIndex = -1;
    for (int i = 0; i < mainStructure->sets_size; i++) {
        if (mainStructure->sets[i].elements == NULL) {
            freeSetIndex = (int) i;
            break;
        }
    }
    if (freeSetIndex == -1) {
        if (!reallocSets(&mainStructure->sets, mainStructure->sets_size, mainStructure->sets_size * 2)) {
            return -1;
        }
        freeSetIndex = (int) mainStructure->sets_size;
        mainStructure->sets_size *= 2;
    }
    return freeSetIndex;
}

/**
 * Function read Set line from file and save set to main structure
 * @param mainStructure main structure with sets and relations
 * @param file file to be read
 * @param line line of set
 * @param universe true if new set will be universe
 * @return true if success false if failure
 */
bool readSet(MainStructure *mainStructure, FILE *file, int line, bool universe) {
    int freeSetIndex = findSetFreeIndex(mainStructure);
    if (freeSetIndex == -1) {
        fprintf(stderr, "SET CANNOT REALLOC SETS ARRAY");
        return false;
    }
    Set new_set = {NULL, 0, line};
    if (!setInit(&new_set)) {
        fprintf(stderr, "SET CANNOT INIT NEW SET");
        return false;
    }
    char buffer[MAX_ELEM_SIZE + 1];
    int setElementIndex = 0;
    while (true) {
        int result = readWord(file, buffer, MAX_ELEM_SIZE);
        if (result == -1) {
            fprintf(stderr, "SET INVALID ELEMENT LEN\n");
            freeNewSet(&new_set, universe);
            return false;
        }
        if (!checkElement(buffer, &new_set)) {
            freeNewSet(&new_set, universe);
            return false;
        }
        if (strlen(buffer) != 0) {
            if (setElementIndex == new_set.size) {
                if (!reallocArrayOfStrings(&new_set.elements, new_set.size, new_set.size * 2)) {
                    freeNewSet(&new_set, universe);
                    fprintf(stderr, "SET CANNOT REALLOC ELEMENTS ARRAY");
                    return false;
                }
                new_set.size *= 2;
            }
            if (universe) {
                char *ptr = calloc(MAX_ELEM_SIZE + 1, sizeof(char));
                if (ptr == NULL) {
                    freeNewSet(&new_set, universe);
                    fprintf(stderr, "UNIVERSE INVALID ELEMENT ALLOCATE");
                    return false;
                }
                strcpy(ptr, buffer);
                new_set.elements[setElementIndex] = ptr;
            } else {
                int foundIndex = getElementUniverseIndex(buffer, mainStructure);
                if (foundIndex == -1) {
                    freeNewSet(&new_set, universe);
                    fprintf(stderr, "SET ELEMENT NOT IN UNIVERSE");
                    return false;
                }
                new_set.elements[setElementIndex] = mainStructure->sets[0].elements[foundIndex];
            }
            setElementIndex++;
        }
        if (result == 0 || result == 1) {
            mainStructure->sets[freeSetIndex] = new_set;
            break;
        }
    }
    return true;
}

/**
 *  Function find free index in relations array in main structure, if array is fully filled, function reallocate array
 * @param mainStructure main structure with sets and relations
 * @return free index in array of relations
 */
int findRelationFreeIndex(MainStructure *mainStructure) {
    int freeRelationIndex = -1;
    for (int i = 0; i < mainStructure->relations_size; i++) {
        if (mainStructure->relations[i].pairs == NULL) {
            freeRelationIndex = (int) i;
            break;
        }
    }
    if (freeRelationIndex == -1) {
        if (!reallocRelations(&mainStructure->relations, mainStructure->relations_size,
                              mainStructure->relations_size * 2)) {
            return -1;
        }
        freeRelationIndex = (int) mainStructure->relations_size;
        mainStructure->relations_size *= 2;
    }
    return freeRelationIndex;
}

/**
 * Function reads relation from line in file and save it to relations array in main structure
 * @param mainStructure main structure with sets and relations
 * @param file input file
 * @param line line of relation
 * @return true if success false if failure
 */
bool readRelationNew(MainStructure *mainStructure, FILE *file, int line) {
    int freeRelationIndex = findRelationFreeIndex(mainStructure);
    if (freeRelationIndex == -1) {
        fprintf(stderr, "RELATION CANNOT REALLOC RELATIONS ARRAY");
        return false;
    }
    Relation new_relation = {NULL, 0, line};
    Pair new_pair = {NULL, NULL};
    if (!relationInit(&new_relation)) {
        fprintf(stderr, "RELATION CANNOT INITIALIZE NEW RELATION");
        return false;
    }
    // 30 chars + () + /0
    char buffer[MAX_ELEM_SIZE + 3];
    int pair_index = 0;
    bool isFirst = true;
    while (true) {
        int result = readWord(file, buffer, MAX_ELEM_SIZE + 2);
        if (result == -1) {
            fprintf(stderr, "RELATION INVALID ELEMENT LEN\n");
            free(new_relation.pairs);
            return false;
        }
        if (strlen(buffer) != 0) {
            if (isFirst && buffer[0] != '(') {
                free(new_relation.pairs);
                fprintf(stderr, "RELATION INVALID PAIR FIRST FORMAT");
                return false;
            }
            if (!isFirst && buffer[strlen(buffer) - 1] != ')') {
                free(new_relation.pairs);
                fprintf(stderr, "RELATION INVALID PAIR SECOUND FORMAT");
                return false;
            }
            char *buffer_chopped;
            if (isFirst) {
                buffer_chopped = buffer + 1;
            } else {
                buffer_chopped = buffer;
                buffer_chopped[strlen(buffer) - 1] = '\0';
            }
            int foundIndex = getElementUniverseIndex(buffer_chopped, mainStructure);
            if (foundIndex == -1) {
                free(new_relation.pairs);
                fprintf(stderr, "RELATION ELEMENT NOT IN UNIVERSE");
                return false;
            }
            if (pair_index == new_relation.size) {
                if (!reallocPairs(&new_relation.pairs, new_relation.size, new_relation.size * 2)) {
                    free(new_relation.pairs);
                    fprintf(stderr, "RELATION CANNOT REALLOC PAIRS ARRAY");
                    return false;
                }
                new_relation.size *= 2;
            }
            if (isFirst) {
                new_pair.first = mainStructure->sets[0].elements[foundIndex];
            } else {
                new_pair.second = mainStructure->sets[0].elements[foundIndex];
            }
            if (!isFirst) {
                for (int i = 0; i < new_relation.size && new_relation.pairs[i].first != NULL; i++) {
                    if (new_pair.first == new_relation.pairs[i].first &&
                        new_pair.second == new_relation.pairs[i].second) {
                        fprintf(stderr, "RELATION INVALID TWO SAME ELEMENTS\n");
                        free(new_relation.pairs);
                        return false;
                    }
                }
                new_relation.pairs[pair_index] = new_pair;
                pair_index++;
            }
            isFirst = !isFirst;
        }
        if (result == 0 || result == 1) {
            if (!isFirst) {
                free(new_relation.pairs);
                fprintf(stderr, "RELATION MISSING SECOND PAIR ELEMENT\n");
                return false;
            }
            mainStructure->relations[freeRelationIndex] = new_relation;
            break;
        }
    }
    return true;
}

/**
 * Function to read line specifiers and call functions to read Sets Commands and relations
 * @param mainStructure main structure with sets and relation
 * @param file input file
 * @return true if success, false if failure
 */
bool readFile(MainStructure *mainStructure, FILE *file) {
    int line = 1;
    int sets_relations_count = 0;
    int commands_count = 0;
    int getChar = fgetc(file);
    if (getChar != 'U') {
        fprintf(stderr, "NO UNIVERSE ON FIRST LINE\n");
        return false;
    }
    getChar = fgetc(file);
    if (getChar == EOF) {
        fprintf(stderr, "NO SETS/RELATIONS AND NO COMMANDS");
        return false;
    }
    if (getChar != ' ' && getChar != '\n') {
        fprintf(stderr, "NO UNIVERSE ON FIRST LINE\n");
        return false;
    }
    if (getChar == '\n') {
        fseek(file, -1, SEEK_CUR);
    }
    if (!readSet(mainStructure, file, line, true)) {
        return false;
    }
    line++;
    bool read_commands = false;
    while (true) {
        getChar = fgetc(file);
        if (getChar == EOF) {
            if (commands_count == 0) {
                fprintf(stderr, "NO COMMANDS\n");
                return false;
            }
            return true;
        }
        if (line == 1001) {
            fprintf(stderr, "LINE COUNT IS MORE THAN 1000\n");
            return false;
        }
        if (read_commands && getChar != 'C') {
            fprintf(stderr, "INVALID LINE DEFINITION IN COMMANDS SECTION\n");
            return false;
        }
        if (getChar != 'S' && getChar != 'R' && getChar != 'C') {
            fprintf(stderr, "INVALID LINE DEFINITION\n");
            return false;
        }
        int line_def = getChar;
        getChar = fgetc(file);
        if (getChar != ' ' && getChar != '\n') {
            fprintf(stderr, "INVALID LINE DEFINITION\n");
            return false;
        }
        if (getChar == '\n') {
            fseek(file, -1, SEEK_CUR);
        }
        if (line_def == 'S') {
            sets_relations_count++;
            if (!readSet(mainStructure, file, line, false)) {
                return false;
            }
        } else if (line_def == 'R') {
            sets_relations_count++;
            if (!readRelationNew(mainStructure, file, line)) {
                return false;
            }
        } else {
            commands_count++;
            if (!read_commands) {
                if (sets_relations_count == 0) {
                    fprintf(stderr, "NO SETS AND RELATIONS\n");
                    return false;
                }
                printSets(mainStructure);
                printRelations(mainStructure);
            }
            if (!readCommands(mainStructure, file)) {
                return false;
            }
            read_commands = true;
        }
        line++;
    }
    return true;
}

/**
 * Main function to execute program
 * @param argc number of program arguments
 * @param argv program arguments array
 * @return 1 if failure, 0 if success
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "invalid number of arguments");
        return 1;
    }
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Invalid input file");
        return 1;
    }
    MainStructure mainStructure = {NULL, 0,
                                   NULL, 0,
    };
    if (!mainStructureAllocate(&mainStructure)) {
        fclose(input_file);
        return 1;
    }
    if (!readFile(&mainStructure, input_file)) {
        freeMainStructure(&mainStructure);
        fclose(input_file);
        return 1;
    }

    fclose(input_file);
    freeMainStructure(&mainStructure);
    return 0;
}