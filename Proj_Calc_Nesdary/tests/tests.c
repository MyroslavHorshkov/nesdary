#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <calcilitir.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>

void test_normal_case(){
    char expr [] = {"1000 - 7"};
    if(evaluate(expr) == 993) {
        printf("PASSED");
    } else {
        printf("FAILED");
    }
    printf("\n");
}

void test_multisign(){
    char expr [] = {"4 - 3 * 4 ^ 0.5"};
    if(evaluate(expr) == -2) {
        printf("PASSED");
    } else {
        printf("FAILED");
    }
    printf("\n");
}

void test_float(){
    char expr [] = {"10 * 0.25"};
    if(fabs(evaluate(expr) - 2.5) < 1e-9) {
        printf("PASSED");
    } else {
        printf("FAILED");
    }
    printf("\n");
}

void test_parenthesis(){
    char expr [] = {"(5 + 3)(9 - 6)"}; 
    if(evaluate(expr) == 24) {
        printf("PASSED");
    } else {
        printf("FAILED");
    }
    printf("\n");
}

void test_multiple_parenthesi(){
    char expr [] = {"2(6 * (7 - 2))(5 - 1)"};
    if(evaluate(expr) == 240) {
        printf("PASSED");
    } else {
        printf("FAILED");
    }
    printf("\n");
}


void test_null(){
    char expr[] = "";
    if(evaluate(expr) == 0) {
        printf("PASSED");
    } else {
        printf("FAILED");
    }
    printf("\n");
}

int main() {
    printf("^*^*STARTING TESTS*^*^\n\n");

    test_normal_case();
    test_float();
    test_multiple_parenthesi();
    test_multisign();
    test_null();
    test_parenthesis();

    printf("\n^*^*TESTS COMPLETE*^*^\n");
    return 0;
}
