// In Bubble sort we compares two adjacent elements and swaps them until they are in the intended order.
// You have given positive integer N, the size of an array as input. Take an array of size N as input and sort this array
// by using Bubble sort. You must make a function for swapping numbers by using pass by reference.

#include <stdio.h>

void bubble_sort(int n,int *ara);
int main()
{
    int n;
    scanf("%d",&n);
    int ara[n];
    for (int i = 0; i <n ; i++)
    {
        scanf("%d",&ara[i]);
    }
    bubble_sort(n,*ara);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",ara[i]);
    }
}

void bubble_sort(int n,int *ara)
{
    int temp=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1 ; j++)
        {
            if (*(ara+j)>*(ara+(j+1)))
            {
                temp= *(ara+j);
                *(ara+j) = *(ara+(j+1));
                *(ara+(j+1))=temp;
            }
            
        }
        
    }
    
}