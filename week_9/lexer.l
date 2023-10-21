%{
#include <stdio.h>
#include "calculator.tab.h"
%}

%%

[0-9]+      { yylval = atof(yytext); return NUMBER; }
"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }
"("         { return '('; }
")"         { return ')'; }
\n          { return 0; } // Ignore newline characters
[ \t]       ; // Ignore spaces and tabs

.           { fprintf(stderr, "Error: Invalid character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}
