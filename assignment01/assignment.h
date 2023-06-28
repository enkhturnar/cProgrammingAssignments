#include <stdlib.h>
#include <stdio.h>

// return bitwise AND of 2 integers
int bitwiseAND(int a, int b);

// return count of 1s in binary representation of x.
int count_number_of_1s(int x);

// return hexadecimal (in string form) representation of x.
char* convert_int_to_hex(int x);

// use qsort to sort array of integers by number of ones ascending order.
// if equal number of ones smaller int comes first
void sort_ints_by_1s(int* arr, size_t length);

/*
    IMPLEMENTATIONS
*/

int bitwiseAND(int a, int b){
    // do not use built in and-operator. 
    // return a & b  is a trivial correct solution.
    // use bitshift operators '>>' and '<<'.

    // printf("-----a is %d and b is %d\n", a, b);
    if (a==0 || b==0){
        return 0;
    }
    if (a==(-1)){
        return b;
    }
    if (b==(-1)){
        return a;
    }
    int sign = 1;
    if (a < 0 && b < 0){
        sign = -1;
    }
    int ans = 0;
    a = abs(a);
    b = abs(b);
    int size = sizeof(a)*8-1;
    int minimum;
    if (a>>size < b>>size){
        minimum = a>>size;
    }
    else {
        minimum = b>>size;
    }
    ans += minimum;
    // printf("Right shift of a by size %d: %d\n", size, a >> size);
    // printf("Right shift of b by size %d: %d\n", size, b >> size);
    // printf("Ans is %d at 0 \n", ans);
    for (int i = size-1; i >= 0; i--){
        if ((a >> i) - (a >> i+1)*2 < (b >> i) - (b >> i+1)*2){
            minimum = (a >> i) - (a >> i+1)*2;
        }
        else {
            minimum = (b >> i) - (b >> i+1)*2;
        }
        // printf("Right shift of a by size %d: %d\n", i, a >> i);
        // printf("Right shift of b by size %d: %d\n", i, b >> i);
        // printf("Minimum is %d at %d\n", minimum, i);
        if (minimum > 0){
            int toAdd = 1;
            for (int j = 1; j <= i; j++){
                toAdd *= 2;
            }
            ans += toAdd;
        }
        // printf("ans is %d at %d\n", ans, i);
    }

    return ans*sign;
}

int count_number_of_1s(int x){
    // printf("-----x is %d\n", x);
    int ans = 0;
    if (x > 0){
        int size = sizeof(x)*8-1;
        for (int i = size-1; i >= 0; i--){
            if ((x >> i) - (x >> i+1)*2 > 0){
                ans += 1;
            }
        }
    }
    else {
        int size = sizeof(x)*8-1;
        ans += 1;
        for (int i = size-1; i >= 0; i--){
            // printf("Right shift of x by size %d: %d\n", i, x >> i);
            // printf("sum of them is %d\n", ((x >> i) + (x >> i+1)*2));
            int signint = 0;
            if ((x >> i) + (x >> i+1)*2 < 0){
                signint -= ((x >> i) + (x >> i+1)*2);
            }
            else {
                signint += ((x >> i) + 2*(x>>(i+1)));
            }
            if (signint % 2 == 1){
                // printf("ans incremented by 1");
                ans += 1;
            }
        }
    }
    return ans;
}

char* convert_int_to_hex(int x){
    
    return NULL;
}

void sort_ints_by_1s(int* arr, size_t length){
    ;
}