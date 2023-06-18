#include <stdlib.h>
#include <stdio.h>
// Do not import other libraries

// return positive int if s1 > s2, 
//        negative int if s1 < s2, 
//                   0 if s1 = s1
int string_cmp(const char* s1, const char* s2);

// return length of given string
size_t string_length(char* s);

// reverse given string
void string_reverse(char* s);

// sort list of strings (arrLength specifies number of strings)
//                      (maxWordLength specifies max length of each string)
void string_list_sort(char** arr, size_t arrLength, size_t maxWordLength);

// remove all occurances of char x from string s
void string_remove_char(char* s, char x);


/*
    IMPLEMENTATIONS
*/


int string_cmp(const char* s1, const char* s2){
    while (*s1 == *s2) {
        if (*s1 != '\0' && *s2 != '\0'){
            s1++;
            s2++;
        }
        else {
            break;
        }
    } 
    if (*s1 > *s2){
        return 1;
    }
    else if (*s1 < *s2) {
        return -1;
    }
    else {
        return 0;
    }
}

size_t string_length(char* s){
    size_t size = 0;
    while (*s != '\0'){
        size += 1;
        s++;
    }
    return size;
}

void string_reverse(char* s){

}

// use qsort(), qsort is defined in <csdlib.h>
// use string_cmp after implementing
void string_list_sort(char** arr, size_t arrLength, size_t maxWordLength){
}

void string_remove_char(char* s, char x){
}