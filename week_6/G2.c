#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void push(char value);
char pop();
bool parseS();
bool parseA();
bool parseB();

char stack[100];
int top = -1;

int main() {
    printf("Enter a string: ");
    char input[100];
    scanf("%s", input);

    // Initialize the stack with a bottom marker
    push('$');

    // Initialize the input pointer
    int inputIndex = 0;
    char currentSymbol = input[inputIndex];

    // Start parsing S
    if (parseS()) {
        if (currentSymbol == '\0') {
            printf("Parsing successful.\n");
        } else {
            printf("Parsing failed: Unparsed symbols remaining.\n");
        }
    } else {
        printf("Parsing failed.\n");
    }

    return 0;
}

void push(char value) {
    if (top >= sizeof(stack) / sizeof(stack[0]) - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

char pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

bool parseS() {
    // Parsing S
    if (parseA() && parseA()) {
        return true;
    }
    return false;
}

bool parseA() {
    char currentSymbol = pop();
    if (currentSymbol == 'a') {
        if (parseB()) {
            return true;
        }
    } else if (currentSymbol == 'e') {
        return true;
    }
    return false;
}

bool parseB() {
    char currentSymbol = pop();
    if (currentSymbol == 'b') {
        return true;
    }
    return false;
}
