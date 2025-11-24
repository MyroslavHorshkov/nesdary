#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 1000

//Stacks
double numStack[MAX];
int numTop = -1;

char opStack[MAX];
int opTop = -1;

void pushNum(double x) {
    numStack[++numTop] = x;
}
double popNum() {
    return numStack[numTop--];
}

void pushOp(char x) {
    opStack[++opTop] = x;
}
char popOp() {
    return opStack[opTop--];
}


//Operation importance
int precedence(char op) {
    if (op == '+' || op == '-'){
        return 1;
    }
    if (op == '*' || op == '/'){
        return 2;
    }
    if (op == '^'){
        return 3;
    }
    return 0;
}

//Operation application
void applyOp() {
    double b = popNum();
    double a = popNum();
    char op = popOp();

    switch (op) {
        case '+': 
            pushNum(a + b);
            break;
        case '-':
            pushNum(a - b);
            break;
        case '*':
            pushNum(a * b);
            break;
        case '/':
            pushNum(a / b);
            break;
        case '^':
            pushNum(pow(a, b));
            break;
    }
}

//Checking if char is an operation
int isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

//Caluculating the result
double evaluate(const char *expr) {
    int i = 0;

    while (expr[i]) {
        if (isspace(expr[i])) {
            i++;
            continue;
        }

        if (expr[i] == '(') {
            if (i > 0 && (isdigit(expr[i-1]) || expr[i-1] == ')' )) {
                while (opTop >= 0 && precedence(opStack[opTop]) >= precedence('*')){
                    applyOp();
                }
                pushOp('*');
            }

            pushOp('(');
            i++;
            
            printf("\n");
            continue;
        }

        
        if (isdigit(expr[i]) || expr[i] == '.') {
            char buf[100];
            int j = 0;

            while (isdigit(expr[i]) || expr[i] == '.') {
                buf[j++] = expr[i++];
            }
            buf[j] = '\0';

            pushNum(atof(buf));
            continue;
        }

        
        if (expr[i] == ')') {
            while (opTop >= 0 && opStack[opTop] != '(') {
                applyOp();
            }
            popOp(); 
            i++;
            continue;
        }

        
        if (isOperator(expr[i])) {
            char op = expr[i];
            while (opTop >= 0 && precedence(opStack[opTop]) >= precedence(op)){
                applyOp();
            }
            pushOp(op);
            i++;
            continue;
        }

        
        printf("Invalid input.\n");
        exit(1);
    }

    while (opTop >= 0)
        applyOp();

    return popNum();
}