%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *msg);
%}

%token id

%%
E: E '+' T   { printf("+ "); }
 | T
 ;

T: T '*' F   { printf("* "); }
 | F
 ;

F: P '^' F   { printf("^ "); }
 | P
 ;

P: '(' E ')' { printf("( "); }
 | id       { printf("%s ", yytext); }
 ;

%%
void yyerror(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
}

int main() {
    yyparse();
    return 0;
}
