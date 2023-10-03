%{
#include <stdio.h>
#include <stdlib.h>
%}

%option noyywrap

%x COMMENT
%x SINGLE_LINE_COMMENT

%%

"/*"            { BEGIN(COMMENT); }
<COMMENT>[^*]+  { /* Skip characters within comments */ }
<COMMENT>\n     { /* Skip newlines within comments */ }
<COMMENT>"*/"   { BEGIN(INITIAL); printf("Multi-line comment: %s\n", yytext); }
<COMMENT>.      { /* Skip any other character within comments */ }
"//"            { BEGIN(SINGLE_LINE_COMMENT); }
<SINGLE_LINE_COMMENT>[^\n]* { /* Skip characters within single-line comments */ }
<SINGLE_LINE_COMMENT>\n     { BEGIN(INITIAL); printf("Single-line comment: %s\n", yytext); }

%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s input.c\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("Error opening input file");
        return 1;
    }

    yyin = input;
    yylex();

    fclose(input);
    return 0;
}
