// You are given two integer x and y. Now you have to find the average of this two integer. Implement this by using pointers.

#include<stdio.h>

float find_average(int *a,int *b);

int main()
{
    int a,b; 
    scanf("%d %d",&a,&b);
    printf("%0.2f",find_average(&a,&b));
}
float find_average(int *a,int *b)
{
    return ((float)(*a+*b)/2);
}