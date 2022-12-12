// You are given two positive integers n and m . Now calculate the value of n to the power m using recursion.

#include<stdio.h>

int fun(int base, int power)
{
    if (power==0)
    {
        return 1;
    }
    else
        return fun(base,power-1)*base;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%d",fun(n,m));
}