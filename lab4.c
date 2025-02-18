#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void)
{
    int num = 0;
    printf("Enter Number: ");
    scanf("%i", &num);
    int i = 1;
    printf("Result: ");
    while (i <= num)
    {
        printf(" %i, ",fibonacci(i));
    }
    printf("\n");

    return 0;
}