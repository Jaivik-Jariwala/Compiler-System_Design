%{
#include <stdio.h>
#include <math.h>
%}

%token NUMBER

%left '+' '-'
%left '*' '/'
%right '^'

%%
calc:   expr    { printf("Result: %lf\n", $1); }
    ;

expr:   expr '+' expr   { $$ = $1 + $3; }
    |   expr '-' expr   { $$ = $1 - $3; }
    |   expr '*' expr   { $$ = $1 * $3; }
    |   expr '/' expr   { $$ = $1 / $3; }
    |   expr '^' expr   { $$ = pow($1, $3); }
    |   NUMBER          { $$ = $1; }
    |   '(' expr ')'     { $$ = $2; }
    ;

%%

int main() {
    yyparse();
    return 0;
}
