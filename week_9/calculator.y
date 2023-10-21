%{
#include <stdio.h>
%}

%token NUMBER
%left '+' '-'
%left '*' '/'

%%

calc: expr { printf("Result: %lf\n", $1); }
    ;

expr: expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { $$ = $1 / $3; }
    | '(' expr ')'  { $$ = $2; }
    | NUMBER       { $$ = $1; }
    ;

%%

int main() {
    yyparse();
    return 0;
}
