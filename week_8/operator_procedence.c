#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the operator precedence table
int precedence[128] = {0};

// Stack to hold operators and operands
char stack[100];
int top = -1;

// Parsing table for operator precedence
char parsing_table[7][7] = {
    {' ', '>', '>', '<', '<', '<', '>'},
    {' ', '>', '>', '<', '<', '<', '>'},
    {'>', '>', '>', '>', '<', '<', '>'},
    {'>', '>', '>', '>', '<', '<', '>'},
    {'<', '<', '<', '<', '<', '=', 'E'},
    {' ', '>', '>', '>', 'E', '>', '>'},
    {'<', '<', '<', '<', '<', ' ', 'A'}
};

// Function to push a character onto the stack
void push(char ch) {
    top++;
    stack[top] = ch;
}

// Function to pop a character from the stack
char pop() {
    char ch = stack[top];
    top--;
    return ch;
}

// Function to get the precedence of an operator
int getPrecedence(char ch) {
    return precedence[ch];
}

// Function to check if the input string is valid
bool isValidString(char *input) {
    int len = strlen(input);
    input[len] = '$'; // Append '$' to the end of the input string
    input[len + 1] = '\0';
    top = -1; // Reset the stack

    // Push '$' onto the stack
    push('$');

    // Initialize the index for the input string
    int index = 0;

    while (top >= 0) {
        char topOfStack = stack[top];
        char currentSymbol = input[index];

        int stackPrecedence = getPrecedence(topOfStack);
        int inputPrecedence = getPrecedence(currentSymbol);

        char action = parsing_table[stackPrecedence][inputPrecedence];

        if (action == '<' || action == '=') {
            push(currentSymbol);
            index++;
        } else if (action == '>') {
            pop();
        } else if (action == 'A') {
            return true; // String is Accepted
        } else if (action == 'E') {
            return false; // String is Rejected
        } else {
            printf("Error: Invalid Action\n");
            return false;
        }
    }

    return false;
}

int main() {
    // Initialize the operator precedence table
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['('] = 0;

    char input_string[] = "(a,a)";
    bool valid = isValidString(input_string);

    if (valid) {
        printf("String is Accepted\n");
    } else {
        printf("String is Rejected\n");
    }

    return 0;
}
