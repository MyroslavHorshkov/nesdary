#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int calc(int a, int b, char sign){
    int res = 0;

    if (sign == 43){
        res = a+b;
    }
    else if (sign == 45){
        res = a-b;
    }
    else if (sign == 42){
        res = a*b;
    }
    else if (sign == 47){
        res = a/b;
    }
    else {
        printf("Wrong operation");
        exit(1);
    }
    printf("Result: %d \n", res);
    return 0;
}


int main(){
    int a = 0;
    int b = 0;
    char sign;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter operation sign: ");
    scanf(" %c", &sign);

    printf("Enter second number: ");
    scanf("%d", &b);

    calc(a, b, sign);
}