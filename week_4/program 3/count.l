%{
int lineCount = 0;
int wordCount = 0;
int charCount = 0;
%}

%%
\n      { lineCount++; }
.       { charCount++; }
[a-zA-Z]+   { wordCount++; charCount += yyleng; }
%%

int yywrap() {
    return 1;  // Indicate that there are no more files to process
}

int main() {
    yylex();
    printf("Lines: %d\nWords: %d\nCharacters: %d\n", lineCount, wordCount, charCount);
    return 0;
}
