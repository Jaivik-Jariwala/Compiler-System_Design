%{
    int n = 0;
%}

%%
[a-zA-Z0-9]+    { n++; }     /* Match any alphanumeric characters and increment n */
[+*/=.;#-]      { n++; }     /* Match specific symbols and increment n */

<<EOF>>         { printf("The number of tokens in code: %d\n", n); return 0; }
%%

int main() {
    yylex();
    return 0;
}
