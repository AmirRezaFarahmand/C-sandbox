#include<stdio.h>

#define MAXn (10010)

int f[MAXn];

int fib(int n)
{
    if (n == 1 || n == 0)
        return 1;
    
    if (f[n])
        return f[n];
        
    return f[n] = fib(n - 1) + fib(n - 2);  
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", fib(n));
}
