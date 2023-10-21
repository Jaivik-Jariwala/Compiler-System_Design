#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Operator Precedence Parsing Table
char table[6][6] = {
    {'>', '>', '<', '<', '<', '>'},
    {'>', '>', '<', '<', '<', '>'},
    {'>', '>', '>', '>', '<', '>'},
    {'<', '<', '<', '<', '<', '='],
    {'>', '>', '>', '>', '=', '>'},
    {'<', '<', '<', '<', '<', ' '},
};

// Stack to hold operators
char stack[100];
int top = -1;

// Push operation on the stack
void push(char ch) {
    stack[++top] = ch;
}

// Pop operation from the stack
char pop() {
    if (top == -1)
        return '$';
    else
        return stack[top--];
}

// Function to get the precedence of an operator
char getPrecedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return '+';
        case '*':
        case '/':
            return '*';
        case '(':
            return '(';
        case ')':
            return ')';
        case '$':
            return '$';
        default:
            return 'i'; // 'i' for identifier
    }
}

// Operator Precedence Parsing
int operatorPrecedenceParsing(char* expression) {
    int len = strlen(expression);
    expression[len] = '$'; // Add end marker
    expression[len + 1] = '\0';

    push('$'); // Push end marker onto the stack
    int i = 0;
    char token = expression[i];

    while (top != -1) {
        if (token == stack[top]) {
            pop();
            i++;
            token = expression[i];
        } else {
            char stackTop = getPrecedence(stack[top]);
            char inputToken = getPrecedence(token);
            if (table[stackTop - 'E'][inputToken - 'E'] == '<' || table[stackTop - 'E'][inputToken - 'E'] == '=') {
                push(token);
                i++;
                token = expression[i];
            } else {
                printf("Invalid expression\n");
                return 0;
            }
        }
    }

    printf("Valid expression\n");
    return 1;
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);
    if (operatorPrecedenceParsing(expression))
        printf("Expression is valid\n");
    else
        printf("Expression is invalid\n");
    return 0;
}
