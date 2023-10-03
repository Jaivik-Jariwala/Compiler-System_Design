%{
    int n=0;
}%
%%
    [a-z|A-Z|0-9]*|[0-9]*|
    ["+","-","*","=",".",";","#"]
        {n++;}
%%

main()
{
     gglex()
     print("the number of tokens in code /d",n);
}