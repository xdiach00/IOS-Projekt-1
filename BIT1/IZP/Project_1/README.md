# Password Checker - first IZP project in FIT VUT

1. Clone repository
2. $ make 
3. ./pwcheck LEVEL PARAM [--stats] <input_file

LEVEL - (1-4) security level:
  1) At least 1 big and 1 small letter
  2) At least PARAM groups of:
    1. One small letter
    2. One big letter
    3. One number
    4. One symbol
  3) The password does not contain a substring of identical characters with a length of at least PARAM
  4) The password does not contain two identical substrings with a a length of at least PARAM
  
--stats is an optional parameter that will display statistics for all passwords entered
