#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <calcilitir.h>

int main() {
    char expr[256];

    printf("Enter expression: ");
    fgets(expr, sizeof(expr), stdin);

    int numTop = -1;
    int opTop = -1;

    double result = evaluate(expr);
    printf("Result = %g\n", result);

    return 0;
}