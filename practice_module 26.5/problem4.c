// You are given an R, the radius of a circle. Now your task to find the area of that circles. Implement this by using function.

#include<stdio.h>

int take_radius();
float circle_area(int r);

int main()
{
    int r=take_radius();
    printf("%0.3f",circle_area(r));
}
int take_radius()
{
    int radius;
    scanf("%d",&radius);
    return radius;
}
float circle_area(int r)
{
    return (float)(3.14159*r*r);
}