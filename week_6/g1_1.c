#include <stdio.h>
#include <string.h>

#define SUCCESS 1
#define FAILED 0

int S();
int A();
int B();

const char *cursor;
char string[64];

int main()
{
    puts("Enter the string");
    sscanf("aabb", "%s", string);
    cursor = string;
    puts("");
    puts("Input      Action");
    puts("--------------------------------");

    if (S() && *cursor == '\0') {
        puts("--------------------------------");
        puts("String is successfully parsed");
        return 0;
    } else {
        puts("--------------------------------");
        puts("Error in parsing String");
        return 1;
    }
}

int S()
{
    printf("%-16s S -> A A\n", cursor);
    if (A()) {
        if (A())
            return SUCCESS;
        else
            return FAILED;
    } else
        return FAILED;
}

int A()
{
    printf("%-16s A -> a B | ε\n", cursor);
    if (*cursor == 'a') {
        cursor++;
        if (B())
            return SUCCESS;
        else
            return FAILED;
    } else {
        printf("%-16s A -> ε\n", cursor);
        return SUCCESS; // Epsilon production for "e"
    }
}

int B()
{
    printf("%-16s B -> b\n", cursor);
    if (*cursor == 'b') {
        cursor++;
        return SUCCESS;
    }
    return FAILED;
}
