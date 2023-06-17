#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "assignment00.h"


void assert_true(bool a, char* msg) {
    if (!a) {
        printf("%s: %d != true\n", msg, a);
        assert(false);
    }
}

void assert_false(bool a, char* msg) {
    if (a) {
        printf("%s: %d != false\n", msg, a);
        assert(false);
    }
}

void assert_eq_size_t(size_t a, size_t b, char* msg) {
    if (a != b) {
        printf("%s: %ld != %ld\n", msg, a, b);
        assert(false);
    }
}
void assert_eq_int(int a, int b, char* msg) {
    if (a != b) {
        printf("%s: %d != %d\n", msg, a, b);
        assert(false);
    }
}


void test_string_cmp();
void test_string_length();
void test_string_reverse();
void test_string_list_sort();

int main() {
    test_string_cmp();
    test_string_length();
    test_string_reverse();
    test_string_list_sort();
    printf("ALL TESTS PASS!\n");
    return 0;
}

void test_string_cmp() {
    {
        char str1[] = "abcadadwqe";
        char str2[] = "abcadadwqe";
        assert_true(string_cmp(str1, str2) == 0, "abcadadwqe = abcadadwqe");
    }
    {
        char str1[] = "ab";
        char str2[] = "a";
        assert_true(string_cmp(str1, str2) > 0, "ab > a");
        assert_true(string_cmp(str2, str1) < 0, "a < ab");
    }
    {
        char str1[] = "a";
        char str2[] = "";
        assert_true(string_cmp(str1, str2) > 0, "a > ''");
        assert_true(string_cmp(str2, str1) < 0, "'' < a");
    }
    {
        char str1[] = "";
        char str2[] = "";
        assert_true(string_cmp(str1, str2) == 0, "'' > ''");
    }
    {
        char str1[] = "abb";
        char str2[] = "abc";
        assert_true(string_cmp(str1, str2) < 0, "abb < abc");
        assert_true(string_cmp(str2, str1) > 0, "abc > abb");
    }
    printf("test_string_cmp PASS!\n");
}

void test_string_length() {
    {
        char str[] = "!laalLASD1321!!";
        assert_eq_size_t(string_length(str), 15, "correct size");
    }
    {
        char str[] = "! ! ! ";
        assert_eq_size_t(string_length(str), 6, "correct size");
    }
    {
        char str[] = "!\n!\n!\n";
        assert_eq_size_t(string_length(str), 6, "correct size");
    }
    {
        char str[] = " \n \t ";
        assert_eq_size_t(string_length(str), 5, "correct size");
    }

    {
        char str[] = "";
        assert_eq_size_t(string_length(str), 0, "correct size");
    }
    {
        char str[13] = "a";
        assert_eq_size_t(string_length(str), 1, "correct size");
    }
    printf("test_string_length PASS!\n");
}

void test_string_reverse() {
    {
        char str1[] = "abb";
        char str2[] = "bba";
        string_reverse(str1);
        assert_true(strcmp(str1, str2) == 0, "abb -> bba");
    }
    {
        char str1[] = "abc";
        char str2[] = "cba";
        string_reverse(str1);
        assert_true(strcmp(str1, str2) == 0, "abc -> cba");
    }
    {
        char str1[] = "aa";
        char str2[] = "aa";
        string_reverse(str1);
        assert_true(strcmp(str1, str2) == 0, "aa -> aa");
    }
    {
        char str1[] = "";
        char str2[] = "";
        string_reverse(str1);
        assert_true(strcmp(str1, str2) == 0, "'' -> ''");
    }
    {
        char str1[] = "\n";
        char str2[] = "\n";
        string_reverse(str1);
        assert_true(strcmp(str1, str2) == 0, "'' -> ''");
    }
    {
        char str1[] = " \n";
        char str2[] = "\n ";
        string_reverse(str1);
        assert_true(strcmp(str1, str2) == 0, "'' -> ''");
    }
    {
        char str1[] = "\t ";
        char str2[] = " \t";
        string_reverse(str1);
        assert_true(strcmp(str1, str2) == 0, "'' -> ''");
    }
    printf("test_string_reverse PASS!\n");
}
void test_string_list_sort() {
    {
        char words[][3] = { "bb", "cc", "aa" };
        string_list_sort((char**)words, 3, 3);
        char sorted[][3] = { "aa", "bb", "cc" };
        for (int i = 0; i < 3; i++) {
            // printf("'%s' '%s'\n", words[i], sorted[i]);
            assert_true(strcmp(words[i], sorted[i]) == 0, "sort order incorrect");
        }
    }
    {
        char words[][3] = { "b", "ac", "bc" };
        string_list_sort((char**)words, 3, 3);
        char sorted[][3] = { "ac", "b", "bc" };
        for (int i = 0; i < 3; i++) {
            // printf("'%s' '%s'\n", words[i], sorted[i]);
            assert_true(strcmp(words[i], sorted[i]) == 0, "sort order incorrect");
        }
    }
    {
        char words[][5] = { "cb", "", "cbba" };
        string_list_sort((char**)words, 3, 5);
        char sorted[][5] = { "", "cb", "cbba" };
        for (int i = 0; i < 3; i++) {
            // printf("'%s' '%s'\n", words[i], sorted[i]);
            assert_true(strcmp(words[i], sorted[i]) == 0, "sort order incorrect");
        }
    }
    {
        char words[][4] = { "abc", "aab", "acd", "aca", "aba", "aba"};
        string_list_sort((char**)words, 6, 4);
        char sorted[][4] = { "aab", "aba", "aba", "abc", "aca", "acd"};
        for (int i = 0; i < 6; i++) {
            // printf("'%s' '%s'\n", words[i], sorted[i]);
            assert_true(strcmp(words[i], sorted[i]) == 0, "sort order incorrect");
        }
    }
    printf("test_string_list PASS!\n");
}