#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

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

void testClosestWaterDistance();
void testFullyCollapseString();

int main() {
    testClosestWaterDistance();
    testFullyCollapseString();
    printf("ALL TESTS PASS!\n");
    return 0;
}
void testFullyCollapseString(){
    {
        char* ans = fullyCollapseString("aabbaabbaa");
        assert_eq_string(ans, "aabbaabbaa", "wrong answer");
        free(ans);
    }
    {
        char* ans = fullyCollapseString("abbbaccca");
        assert_eq_string(ans, "", "wrong answer");
        free(ans);
    }
    {
        char* ans = fullyCollapseString("caabbba");
        assert_eq_string(ans, "c", "wrong answer");
        free(ans);
    }
    {
        char* ans = fullyCollapseString("aabcccbbaa");
        assert_eq_string(ans, "a", "wrong answer");
        free(ans);
    }
    {
        char* ans = fullyCollapseString("aaaaaaaaaaa");
        assert_eq_string(ans, "aa", "wrong answer");
        free(ans);
    }
    {   
        char* ans = fullyCollapseString("acbbbccabbbacccabbbaccca");
        assert_eq_string(ans, "", "wrong answer");
        free(ans);
    }
    {   
        char* ans = fullyCollapseString("a");
        assert_eq_string(ans, "a", "wrong answer");
        free(ans);
    }
    {   
        char* ans = fullyCollapseString("bxaaaxaaaxbycccyybrrppprr");
        assert_eq_string(ans, "r", "wrong answer");
        free(ans);
    }
    printf("testFullyCollapseString\n");
}
void testClosestWaterDistance() {
    {
        assert_eq_int(closestWaterDistance("water_test_0.txt"), 18, "wrong answer");
    }
    {
        assert_eq_int(closestWaterDistance("water_test_1.txt"), -1, "wrong answer");
    }
    {
        assert_eq_int(closestWaterDistance("water_test_2.txt"), 4, "wrong answer");
    }
    {
        assert_eq_int(closestWaterDistance("water_test_3.txt"), 5, "wrong answer");
    }
    {
        assert_eq_int(closestWaterDistance("water_test_4.txt"), 19, "wrong answer");
    }
    {
        assert_eq_int(closestWaterDistance("water_test_5.txt"), 36, "wrong answer");
    }
    {
        assert_eq_int(closestWaterDistance("water_test_6.txt"), 16, "wrong answer");
    }
    printf("testClosestWaterDistance PASS!\n");
}