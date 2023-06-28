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
    // printf("%d %d\n",a,b);
    // do not use built in and-operator. 
    // return a & b  is a trivial correct solution.
    // use bitshift operators '>>' and '<<'.

    // int sign = 1;
    // if (a < 0 && b < 0){
    //     sign = -1;
    // }
    int ans = 0;
    int powertwo = 1;
    for (int i = 1; i < 31; i++){
        powertwo *= 2;
    }
    if (a < 0 && b < 0){
        ans += (-1)*powertwo*2;
    }
    // if (sign==-1){
    //     ans -= powertwo;
    // }
    // if (a < 0){
    //     a += powertwo;
    // }
    // if (b < 0){
    //     b += powertwo;
    // }
    // powertwo /= 2;
    for (int i = 1; i <= 31; i++){
        if ((a<<i) < 0 && (b<<i) < 0){
            ans += powertwo;
        }
        powertwo /= 2;
    }
    return ans;
}

int count_number_of_1s(int x){
    // printf("-----x is %d\n", x);
    int ans = 0;
    int poweroftwo = 1;
    for (int i = 0; i <= 30; i++){
        if (bitwiseAND(x, poweroftwo) > 0){
            ans += 1;
        }       
        poweroftwo *= 2;
    }
    if (x<0){
        ans += 1;
    }
    return ans;
}

char* convert_int_to_hex(int x){
    char binary[33];
    int poweroftwo = 1;
    binary[32] = '\0';
    int idx = 31;
    for (int i = 0; i <= 30; i++){
        if (bitwiseAND(x, poweroftwo) > 0){
            binary[idx] = '1';
        }       
        else {
            binary[idx] = '0';
        }
        poweroftwo *= 2;
        idx--;
    }
    // printf("idx is now %d \n", idx);
    if (x<0){
        binary[idx] = '1';
    }
    else {
        binary[idx] = '0';
    }
    char hex[9];
    hex[8] = '\0';
    int index = 0;

    for (int i = 0; i < 32; i += 4){
        int sum = 0;
        if (binary[i] == '1'){
            sum += 8;
        }
        if (binary[i+1] == '1'){
            sum += 4;
        }
        if (binary[i+2] == '1'){
            sum += 2;
        }
        if (binary[i+3] == '1'){
            sum += 1;
        }
        if (sum == 0){
            hex[index] = '0';
        }
        if (sum == 1){
            hex[index] = '1';
        }
        if (sum == 2){
            hex[index] = '2';
        }
        if (sum == 3){
            hex[index] = '3';
        }
        if (sum == 4){
            hex[index] = '4';
        }
        if (sum == 5){
            hex[index] = '5';
        }
        if (sum == 6){
            hex[index] = '6';
        }
        if (sum == 7){
            hex[index] = '7';
        }
        if (sum == 8){
            hex[index] = '8';
        }
        if (sum == 9){
            hex[index] = '9';
        }
        if (sum == 10){
            hex[index] = 'A';
        }
        if (sum == 11){
            hex[index] = 'B';
        }
        if (sum == 12){
            hex[index] = 'C';
        }
        if (sum == 13){
            hex[index] = 'D';
        }
        if (sum == 14){
            hex[index] = 'E';
        }
        if (sum == 15){
            hex[index] = 'F';
        }
        index++;
    }
    char* ptr = hex;
    return ptr;
}

int compare(const void* a, const void* b){
    const int x = *((int *)a);
    const int y = *((int *)b);
    if (count_number_of_1s(x) < count_number_of_1s(y)){
        return -1;
    }
    else if (count_number_of_1s(y) < count_number_of_1s(x)){
        return 1;
    }
    else if (x < y){
        return -1;
    }
    else if (y < x){
        return 1;
    }
    else {
        return 0;
    }
}

void sort_ints_by_1s(int* arr, size_t length){
    qsort(arr, length, 4, compare);
}