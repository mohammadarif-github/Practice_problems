//You are given an integer n . Now print the sum of first n natural numbers.Implement it using recursion.
#include<stdio.h>

int recurse_sum(int n)
{
    if (n>0)
    {
        return recurse_sum(n-1)+n;
    }
    else 
        return 0; 
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",recurse_sum(n));
}
