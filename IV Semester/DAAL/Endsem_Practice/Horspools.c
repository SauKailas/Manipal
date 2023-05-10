#include<stdio.h>
#include<string.h>

int shift_table[100];

void ShiftTable(char pattern[]){
    int m=strlen(pattern);

    for(int i=0; i<500; i++)
        shift_table[i]=m;

    for(int i=0; i<m-1; i++)
        shift_table[pattern[i]]=m-1-i;
}

int Horspool(char text[], char pattern[]){
    int n=strlen(text);
    int m=strlen(pattern);
    int i=0;

    while(i<=n-1)
    {
        int k=0;
        while(k<=m-1 && text[i-k]==pattern[m-1-k])
            k++;

        if(k==m)
            return i-m+1;
        else    
            i+=shift_table[text[i]];
    }
    return -1;
}

int main()
{
    char text[100], pattern[100];

    printf("Enter a text:\n");
    gets(text);
    printf("Enter a pattern:\n");
    gets(pattern);

    ShiftTable(pattern);

    int val=Horspool(text, pattern);

    if(val==-1)
        printf("Pattern NOT found!\n");
    else
        printf("Pattern STARTS at index %d!\n", val+1);
        
    return 0;
}