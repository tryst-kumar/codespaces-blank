#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main(void)
{
    int n = 0;
    printf("Enter the number : \n");
    scanf("%d", &n);

    printf("Result : %i\n", factorial(n));

    return 0;
}