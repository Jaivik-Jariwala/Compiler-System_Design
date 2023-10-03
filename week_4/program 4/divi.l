%{
#include <stdio.h>
%}

%%
[0-9]+  {
            int num = atoi(yytext);
            if (num % 7 == 0) {
                num += 5;
                printf("Number %d is divisible by 7. Result after adding 5: %d\n", num - 5, num);
            } else {
                printf("Number %d is not divisible by 7.\n", num);
            }
        }
.|\n    { }
%%
int yywrap() {
    return 1;  // Indicate that there are no more files to process
}


int main() {
    yylex();
    return 0;
}
