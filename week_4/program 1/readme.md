# Lex (Flex) Tokenizer Example

This is a simple example of a Lex (Flex) program that tokenizes input text and categorizes it into different types of tokens, such as keywords, identifiers, operators, literals, and more.

## Overview

The provided Lex program takes input text and identifies various types of tokens within it. It then prints out messages indicating the type of each recognized token. The recognized token types are as follows:

- Keywords (e.g., `int`, `float`, `if`, `else`, `while`)
- Identifiers (e.g., variable names)
- Operators (e.g., `+`, `-`, `*`, `/`, `=`)
- Numeric Literals (e.g., `42`, `3.14`)
- Semicolons (`;`)
- Unrecognized characters

## How to Use

1. Install Flex: Ensure that you have Flex (the lexical analyzer generator) installed on your system.

2. Compile the Lex program: Compile the Lex program using the following command:

3. Compile the C code: Compile the generated C code using a C compiler (e.g., GCC):

4. Run the Lexer: Run the compiled executable `lexer` and provide input text. The lexer will tokenize the input and display the categorized tokens.
You can then type in input text, and the program will display the token type for each recognized token.

## Example Usage

Input:

int main() {
int x = 10;
float y = 3.14;
if (x > y) {
printf("x is greater");
} else {
printf("y is greater");
}
return 0;
}

Output:
Keyword: int
Identifier: main
Operator: (
Operator: )
Operator: {
Keyword: int
Identifier: x
Operator: =
Literal: 10
Operator: ;
Keyword: float
Identifier: y
Operator: =
Literal: 3.14
Operator: ;
Keyword: if
Operator: (
Identifier: x
Operator: >
Identifier: y
Operator: )
Operator: {
Keyword: printf
Operator: (
Literal: "x is greater"
Operator: )
Operator: ;
Keyword: else
Operator: {
Keyword: printf
Operator: (
Literal: "y is greater"
Operator: )
Operator: ;
Operator: }
Keyword: return
Literal: 0
Operator: ;
Operator: }

## Note

- This example assumes you have a basic understanding of Flex and C programming.
- The token recognition and categorization rules in the provided Lex program are intentionally kept simple for educational purposes. In real-world scenarios, more complex rules and actions might be required.


