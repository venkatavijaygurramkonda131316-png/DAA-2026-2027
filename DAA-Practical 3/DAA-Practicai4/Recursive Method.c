#include <stdio.h>

long long factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{printf("enter a number:");
    scanf("%d",&n);
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Factorial = %d\n", factorial(n));
    printf("recursive = %d\n",recursive(n));
    return 0;
}