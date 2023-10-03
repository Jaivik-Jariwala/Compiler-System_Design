%{
#include <stdio.h>
int n = 0;
%}

%%
[a-zA-Z_][a-zA-Z0-9_]*|'<='|"=="|"="|"+"|"-"|"*"|[(){}|,;]
[0-9]*"."[0-9]+|[0-9]+ {n++;
printf("%s = %d\n",yytext,yyleng);}
%%

int yywrap() {
    return 1; // Indicate end of input
}

int main() {
    yylex();
    printf("Total number of tokens: %d\n", n);
    return 0;
}
