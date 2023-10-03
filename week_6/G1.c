#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// Function prototypes
void push(int value);
int pop();
int parseExpression();
int parseTerm();
int parseFactor();
void error(const char *message);

char input[100];
int position = 0;

int stack[100];
int top = -1;

int main() {
    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);
    
    int result = parseExpression();
    
    if (input[position] == '\0' || input[position] == '\n') {
        printf("Parse Successful! Result = %d\n", result);
    } else {
        error("Unexpected characters in input");
    }
    
    return 0;
}

void push(int value) {
    if (top >= sizeof(stack) / sizeof(stack[0]) - 1) {
        error("Stack overflow");
    }
    stack[++top] = value;
}

int pop() {
    if (top < 0) {
        error("Stack underflow");
    }
    return stack[top--];
}

int parseExpression() {
    int left = parseTerm();
    
    while (input[position] == '+' || input[position] == '-') {
        char op = input[position++];
        int right = parseTerm();
        if (op == '+') {
            left += right;
        } else {
            left -= right;
        }
    }
    
    return left;
}

int parseTerm() {
    int left = parseFactor();
    
    while (input[position] == '*' || input[position] == '/') {
        char op = input[position++];
        int right = parseFactor();
        if (op == '*') {
            left *= right;
        } else {
            if (right == 0) {
                error("Division by zero");
            }
            left /= right;
        }
    }
    
    return left;
}

int parseFactor() {
    if (isdigit(input[position])) {
        int value = 0;
        while (isdigit(input[position])) {
            value = value * 10 + (input[position] - '0');
            position++;
        }
        return value;
    } else if (input[position] == '(') {
        position++;
        int result = parseExpression();
        if (input[position] == ')') {
            position++;
            return result;
        } else {
            error("Unmatched '('");
        }
    } else {
        error("Invalid character");
    }
}

void error(const char *message) {
    printf("Error: %s\n", message);
    exit(1);
}
