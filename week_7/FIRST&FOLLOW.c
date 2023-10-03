#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool isE(char *input, int *pos);
bool isF(char *input, int *pos);
bool isS(char *input);
void computeFirstSets(char *input);
void computeFollowSets(char *input);

// Function to compute FIRST sets
void computeFirstSets(char *input) {
    printf("FIRST(isE) = {");
    if (isE(input, 0)) {
        printf("'g'");
    }
    printf("}\n");

    printf("FIRST(isF) = {");
    if (isF(input, 0)) {
        printf("'f'");
    }
    printf("}\n");

    printf("FIRST(isS) = {");
    if (isS(input)) {
        printf("'g'");
    }
    printf("}\n");
}

// Function to compute FOLLOW sets
void computeFollowSets(char *input) {
    printf("FOLLOW(isE) = {follow(isS)} = {EOF");
    if (input[0] == 'f') {
        printf(", 'f'");
    }
    printf("}\n");

    printf("FOLLOW(isF) = {follow(isS)} = {EOF}\n");

    printf("FOLLOW(isS) = {follow(isE)} = {EOF");
    if (input[0] == 'f') {
        printf(", 'f'");
    }
    printf("}\n");
}

bool isE(char *input, int *pos) {
    if (input[*pos] == 'g') {
        (*pos)++;
        return true;
    } else {
        return false;
    }
}

bool isF(char *input, int *pos) {
    if (input[*pos] == 'f') {
        (*pos)++;
        return true;
    } else {
        return false;
    }
}

bool isS(char *input) {
    int pos = 0;
    if (isE(input, &pos) && isF(input, &pos)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char input[] = "gfgfggfff";

    // Compute FIRST and FOLLOW sets for the input string
    computeFirstSets(input);
    computeFollowSets(input);

    if (isS(input)) {
        printf("String is in the lang\n");
    } else {
        printf("String is not in the lang\n");
    }
    return 0;
}
