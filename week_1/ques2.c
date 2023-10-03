#include <stdio.h>
#include <string.h>

int main() {
    char keyword[32][10]={
        "auto","double","int","struct","break","else","long",
        "switch","case","enum","register","typedef","char",
        "extern","return","union","const","float","short",
        "unsigned","continue","for","signed","void","default",
        "goto","sizeof","voltile","do","if","static","while"
    } ;
    char str[20]; // Increase the size of the array to accommodate longer keywords
    scanf("%s", str); // Correct the argument to read a string
    int flag=0,i;
    for(i = 0; i < 32; i++) {
        if(strcmp(str, keyword[i])==0) {
            flag=1;
            break; // Once a match is found, no need to continue the loop
        }
    }
    if(flag==1)
        printf("%s is a keyword", str);
    else
        printf("%s is not a keyword", str);

    return 0; // Add a return statement to the main function
}
