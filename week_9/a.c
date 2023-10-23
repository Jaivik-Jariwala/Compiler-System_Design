%{
#include "calculator.tab.h"
%}

%%
[0-9]+(\.[0-9]+)?    { yylval = atof(yytext); return NUMBER; }
[-+*/^()=]           { return yytext[0]; }
[ \t\n]              ;
.                    { fprintf(stderr, "Invalid input: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}
