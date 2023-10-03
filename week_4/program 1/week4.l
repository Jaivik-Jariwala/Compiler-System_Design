%{
#include <stdio.h>
%}

%option noyywrap

%%
"int"|"float"|"if"|"else"|"while"   { printf("Keyword: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*              { printf("Identifier: %s\n", yytext); }
[+\-\*/=]                           { printf("Operator: %s\n", yytext); }
[0-9]+(\.[0-9]+)?                   { printf("Literal: %s\n", yytext); }
";"                                 { printf("Semicolon\n"); }
[ \t\n]                             { /* Skip whitespace and newline characters */ }
.                                   { printf("Unrecognized: %s\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}
