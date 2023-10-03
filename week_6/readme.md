Grammer 1 
S -> AA
A -> aB | e
B -> b

Grammer 2 
S -> AA


## Overview

The recursive descent parser is a top-down parsing technique where we start with the highest-level non-terminal (in this case, `S`) and recursively expand each non-terminal according to the production rules until we either successfully parse the entire string or encounter an error.

## Code Structure

The code consists of the following main components:

1. **Main Function**: The `main` function serves as the entry point of the program. It reads an input string, initializes the cursor, and invokes the `S` function to start parsing.

2. **Parsing Functions**: There are three parsing functions corresponding to the non-terminals `S`, `A`, and `B`. These functions implement the parsing logic based on the grammar rules.

   - `S()` function handles the non-terminal `S`, which consists of two `A` non-terminals. It checks if two `A`'s can be parsed.
   
   - `A()` function handles the non-terminal `A`, which can produce either 'a' followed by `B` or ε (epsilon, representing an empty string). It checks for 'a' and then calls `B()` if 'a' is found.
   
   - `B()` function handles the non-terminal `B`, which is a terminal symbol 'b'.

3. **Cursor**: The `cursor` is a pointer to the current position in the input string. It is used to keep track of which part of the string is being parsed.

4. **Output**: The parsing process is logged to the console with detailed actions and productions taken for each input character.

## Running the Parser

To run the parser, compile the code using a C compiler (e.g., GCC) and execute the compiled binary. You can input a string to be parsed, and the parser will output whether the string can be successfully parsed according to the given grammar.

## Example

Here's an example of how to use the parser:

