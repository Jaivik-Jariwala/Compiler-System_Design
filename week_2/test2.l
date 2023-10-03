%{
    int n = 0;
%}

%%
[a-zA-Z_][a-zA-Z0-9_]*   { n++; }      /* Match valid identifiers */
"="|"+"|"-"|"=="|"/"      { n++; }      /* Match specific operators */
[0-9]+\.[0-9]+           { n++; }      /* Match floating-point numbers correctly */

<<EOF>>                   { printf("The number of tokens in code: %d\n", n); return 0; }
.                         { /* Ignore unrecognized characters */ }
%%

int main() {
    yylex();
    printf("Total number of tokens: %d\n", n);
    return 0;
}
