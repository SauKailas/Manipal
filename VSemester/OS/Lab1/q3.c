#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    int a = 20;
    float b = 39.24;
    char c = 'K';
    char str[] = "Saurabh";

    printf("a = %d, b = %f, c = %c, str = %s, Hexadecimal for a = %x\n", a, b, c, str, a);

    errno = EPERM;
    printf("Error Access Number : %m\n");

    return 0;
}