#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define structures for First and Follow sets
typedef struct {
    char firstSet[10];
    int count;
} FirstSet;

typedef struct {
    char followSet[10];
    int count;
} FollowSet;

// Define a structure for grammar production rules
typedef struct {
    char nonTerminal;
    char production[20];
} Production;

// Define the LL(1) parsing table
typedef struct {
    char nonTerminal;
    char terminal;
    char production[20];
} LL1TableEntry;

int main() {
    // Define the grammar rules
    Production grammar[] = {
        {'S', "aAB"},
        {'A', "b|epsilon"},
        {'B', "c|epsilon"}
    };

    // Initialize First and Follow sets for each non-terminal
    FirstSet firstSets[3];
    FollowSet followSets[3];

    // Populate First and Follow sets (you need to implement this)

    // Define LL(1) parsing table
    LL1TableEntry parsingTable[] = {
        {'S', 'a', "aAB"},
        {'A', 'b', "b"},
        {'A', 'c', "epsilon"},
        {'A', '$', "epsilon"},
        {'B', 'b', "epsilon"},
        {'B', 'c', "c"},
        {'B', '$', "epsilon"}
    };

    // Print LL(1) parsing table
    printf("LL(1) Parsing Table:\n");
    printf("  %-10s %-10s %-20s\n", "Non-Terminal", "Terminal", "Production");
    for (int i = 0; i < 7; i++) {
        printf("  %-10c %-10c %-20s\n", parsingTable[i].nonTerminal, parsingTable[i].terminal, parsingTable[i].production);
    }

    // Perform parsing using the LL(1) parsing table (you need to implement this)

    return 0;
}
