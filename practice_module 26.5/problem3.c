// You have given positive integer N, the size of an array as input. Take an array of size N as input. Now your task to
// print this array. Implement this by using pointers.

#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int  ara[n];
    for (int  i = 0; i < n; i++)
    {
        scanf("%d",ara+i);
    }
    for (int i = 0; i < n ; i++)
    {
        printf("%d ",*(ara+i));
    }
}