#ifndef CALCILITIR_H
#define CALCILITIR_H


/** 
 * @brief Performs basic mathematic operations, plus exponentiation and squere root. 
 * @brief Works with multiple parenthesis.
 * @brief Works with decimal values. 
 * 
 * @param op Takes an operation to calculate precedence of it.
 * @param x Number or operation to push to stack.
 * @param c Is used to check if char is an operation.
 * @param expr Is a string of chars that is inputed by the user.
 * 
 * @return [precidence] returns a numureical value from 1 to 3 based on the op's importance.
 * @return [isOperator] returns either 1 or 0 based on whether the char is an op or not.
 * @return [evaluate] returns either the string's result or an error message.
 */

int precedence(char op);
void pushNum(double x);
double popNum();
void pushOp(char x);
char popOp();
void applyOp();
int isOperator(char c);
double evaluate(const char *expr);

#endif 