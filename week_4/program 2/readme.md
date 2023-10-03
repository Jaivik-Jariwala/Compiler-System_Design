C Comment Extractor using Lex (Flex)
This is a simple Lex (Flex) code that serves as a lexer/scanner for extracting comments from a C source file. It identifies and displays both multi-line (/* ... */) and single-line (// ...) comments found in the input file.

How to Use
Install Flex: Make sure you have Flex (Lex) installed on your system. If not, you can install it using the package manager for your operating system.

Compile the Lex Code:

flex comment_extractor.l
gcc -o comment_extractor lex.yy.c -lfl
Run the Program:

./comment_extractor input.c
Replace input.c with the path to the C source file from which you want to extract comments.

Understanding the Code
%{
#include <stdio.h>
#include <stdlib.h>
%}
The code begins with a C-style block enclosed in %{ ... %}. This section is used to include necessary header files.

%option noyywrap
This directive indicates that the lexer does not need the yywrap function, which is used to determine if the lexer should continue scanning or terminate.

%x COMMENT
%x SINGLE_LINE_COMMENT
The %x directive defines start conditions for the lexer. Here, we have two start conditions, COMMENT and SINGLE_LINE_COMMENT, which are used to handle multi-line and single-line comments, respectively.

%%
This is the main body of the lexer. The lexer rules are defined in this section.

"/*"            { BEGIN(COMMENT); }
When the lexer encounters the start of a multi-line comment ("/*"), it enters the COMMENT start condition using BEGIN(COMMENT).

<COMMENT>[^*]+  { /* Skip characters within comments */ }
<COMMENT>\n     { /* Skip newlines within comments */ }
Within the COMMENT state, these rules skip characters and newlines within the multi-line comment.

<COMMENT>"*/"   { BEGIN(INITIAL); printf("Multi-line comment: %s\n", yytext); }
When the lexer detects the end of the multi-line comment ("*/"), it prints the extracted comment using printf and then returns to the default state using BEGIN(INITIAL).

"//"            { BEGIN(SINGLE_LINE_COMMENT); }
When the lexer encounters a single-line comment ("//") in the default state, it enters the SINGLE_LINE_COMMENT state.

<SINGLE_LINE_COMMENT>[^\n]* { /* Skip characters within single-line comments */ }
Within the SINGLE_LINE_COMMENT state, this rule skips characters within the single-line comment until a newline is encountered.

<SINGLE_LINE_COMMENT>\n     { BEGIN(INITIAL); printf("Single-line comment: %s\n", yytext); }
When the lexer reaches the end of a line within a single-line comment, it prints the comment using printf and returns to the default state.

%%
This section ends the main body of the lexer.

int main(int argc, char *argv[]) {
    // ...
}
This is the main function of the program. It checks command-line arguments, opens the input file, sets the input stream for the lexer, calls yylex() to initiate lexing, and then closes the input file.

Summary
This Lex code demonstrates how to create a simple lexer to extract and display multi-line and single-line comments from a C source file. It uses start conditions to handle different types of comments and provides an example of how to integrate it into a C program.

Feel free to modify and expand upon this README to suit your needs. You can also add information about how Lex/Flex works, more details about regular expressions and lexer rules, and any other relevant information.




