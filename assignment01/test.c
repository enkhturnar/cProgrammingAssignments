#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "assignment.h"

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

void assert_eq_string(char* a, char* b, char* msg) {
    if (strcmp(a, b) != 0) {
        printf("%s: %s != %s\n", msg, a, b);
        assert(false);
    }
}

void assert_int_array_eq(int* a, int* b, int len, char* msg) {
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            for (int i = 0; i < len; i++) {
                printf("%d ", a[i]);
            }
            printf("!= ");
            {
                for (int i = 0; i < len; i++) {
                    printf("%d ", b[i]);
                }
                printf("; %s\n", msg);
                assert(false);
            }
        }
    }
}

void test_count_number_of_1s();
void test_convert_int_to_hex();
void test_bitwiseAND();
void test_sortByOnes();

int main() {
    test_bitwiseAND();
    test_count_number_of_1s();
    test_convert_int_to_hex();
    test_sortByOnes();
    printf("ALL TESTS PASS!\n");
    return 0;
}
void test_count_number_of_1s() {
    {
        assert_eq_int(count_number_of_1s(1), 1, "1 has 1 one");
    }
    {
        assert_eq_int(count_number_of_1s(2), 1, "2 has 1 one");
    }
    {
        assert_eq_int(count_number_of_1s(44), 3, "44 has 3 ones");
    }
    {
        assert_eq_int(count_number_of_1s(64), 1, "64 has 1 one");
    }
    {
        assert_eq_int(count_number_of_1s(456), 4, "456 has 4 one");
    }
    {
        assert_eq_int(count_number_of_1s(2147483647), 31, "2147483647 has 31 ones");
    }
    {
        assert_eq_int(count_number_of_1s(-1), 32, "-1 has 32 ones");
    }
    {
        assert_eq_int(count_number_of_1s(-2147483647), 2, "-2147483647 has 2 ones");
    }
    {
        assert_eq_int(count_number_of_1s(-2147483627), 4, "-2147483627 has 4 ones");
    }
    {
        assert_eq_int(count_number_of_1s(2147483627), 29, "2147483627 has 29 ones");
    }
    {
        assert_eq_int(count_number_of_1s(-2147483648), 1, "-2147483648 has 1 one");
    }
    {
        assert_eq_int(count_number_of_1s(-2147483648), 1, "-2147483648 has 1 one");
    }
    {
        assert_eq_int(count_number_of_1s(-1073741824), 2, "-1073741824 has 2 one");
    }
    // {
    //     for(int i = -10000; i <= 10000; i++){
    //         printf("%d\n", i);
    //         assert_eq_int(count_number_of_1s(i), count1s(i), "wrong ans");
    //     }
    // }
    printf("test_count_number_of_1s PASS!\n");
}

void test_convert_int_to_hex() {
    {
        char* hex = convert_int_to_hex(1);
        assert_eq_string(hex, "00000001", "conversion incorrect");
        // free(hex);
    }
    {
        char* hex = convert_int_to_hex(2);
        assert_eq_string(hex, "00000002", "conversion incorrect");
        // free(hex);
    }
    {
        char* hex = convert_int_to_hex(15);
        assert_eq_string(hex, "0000000F", "conversion incorrect");
        // free(hex);
    }
    {
        char* hex = convert_int_to_hex(22);
        assert_eq_string(hex, "00000016", "conversion incorrect");
        // free(hex);
    }
    {
        char* hex = convert_int_to_hex(123123);
        assert_eq_string(hex, "0001E0F3", "conversion incorrect");
        // free(hex);
    }
    {
        char* hex = convert_int_to_hex(-123123);
        assert_eq_string(hex, "FFFE1F0D", "conversion incorrect");
        // free(hex);
    }
    {
        char* hex = convert_int_to_hex(2147483647);
        assert_eq_string(hex, "7FFFFFFF", "conversion incorrect");
        // free(hex);
    }
    {
        char* hex = convert_int_to_hex(-444444);
        assert_eq_string(hex, "FFF937E4", "conversion incorrect");
        // free(hex);
    }

    {
        char* hex = convert_int_to_hex(-1);
        assert_eq_string(hex, "FFFFFFFF", "conversion incorrect");
        // free(hex);
    }
    printf("test_convert_int_to_hex PASS!\n");
}

void test_bitwiseAND() {
    {
        assert_eq_int(bitwiseAND(1, 1), 1, "bitwise and incorrect");
    }
    {
        assert_eq_int(bitwiseAND(10, 3), 2, "bitwise and incorrect");
    }
    {
        assert_eq_int(bitwiseAND(30, 15), 14, "bitwise and incorrect");
    }
    {
        assert_eq_int(bitwiseAND(0, -1), 0, "bitwise and incorrect");
    }
    {
        assert_eq_int(bitwiseAND(0, 1312321), 0, "bitwise and incorrect");
    }
    {
        assert_eq_int(bitwiseAND(-1, 1), 1, "bitwise and incorrect");
    }
    {
        assert_eq_int(bitwiseAND(-1, 1), 1, "bitwise and incorrect");
    }
    {
        assert_eq_int(bitwiseAND(-1, 255), 255, "bitwise and incorrect");
    }
    {
        assert_eq_int(bitwiseAND(-1, -2), -2, "bitwise and incorrect");
    }
    {
        assert_eq_int(bitwiseAND(-2, 1), 0, "bitwise and incorrect");
    }
    {
        for (int i = -1000; i <= 1000; i++) {
            for (int j = -1000; j <= 1000; j++) {
                assert_eq_int(bitwiseAND(i, j), i & j, "bitwise and incorrect");
            }
        }
    }

    printf("test_bitwiseAND PASS!\n");
}

void test_sortByOnes() {
    {
        int len = 3;
        int arr[] = { 2, 1, 0 };
        int sorted[] = { 0, 1, 2 };
        sort_ints_by_1s(arr, len);
        assert_int_array_eq(arr, sorted, len, "sort incorrect");
    }
    {
        int len = 4;
        int arr[] = { 2, 1, 8, 4 };
        int sorted[] = { 1, 2, 4, 8 };
        sort_ints_by_1s(arr, len);
        assert_int_array_eq(arr, sorted, len, "sort incorrect");
    }
    {
        int len = 4;
        int arr[] = { 2, 10, 8, 4 };
        int sorted[] = { 2, 4, 8, 10 };
        sort_ints_by_1s(arr, len);
        assert_int_array_eq(arr, sorted, len, "sort incorrect");
    }
    {
        int len = 4;
        int arr[] = { 3, 3, 3, 4 };
        int sorted[] = { 4, 3, 3, 3 };
        sort_ints_by_1s(arr, len);
        assert_int_array_eq(arr, sorted, len, "sort incorrect");
    }
    {
        int len = 4;
        int arr[] = { 3, 3, 3, -1 };
        int sorted[] = { 3, 3, 3, -1 };
        sort_ints_by_1s(arr, len);
        assert_int_array_eq(arr, sorted, len, "sort incorrect");
    }

    {
        int len = 4;
        int arr[] = { 31, 15, 7, -1 };
        int sorted[] = { 7, 15, 31, -1 };
        sort_ints_by_1s(arr, len);
        assert_int_array_eq(arr, sorted, len, "sort incorrect");
    }
    printf("test_sortByOnes PASS!\n");
}