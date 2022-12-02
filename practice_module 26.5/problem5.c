// You have given positive integer N, the size of an array as input. Take an array of size N as input. You have to find the
// sum of those element in array which last digit is zero. Implement this by using function.
// Note - It is guaranteed that each element of an array is at least 2 digit number.

#include<stdio.h>

int find_sum(int n,int *ara);

int main()
{
    int n ;
    scanf("%d",&n);
    int ara[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&ara[i]);
    }
    printf("%d",find_sum(n,&ara));
}

int find_sum(int n,int *ara)
{
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        if (ara[i] %10 == 0)
        {
            sum+= ara[i];
        }
        
    }
    return sum;
}