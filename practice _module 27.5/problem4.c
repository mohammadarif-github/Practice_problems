#include <stdio.h>
void recurse_fun(int x)
{
    if (x > 0)
    {
        printf("%d ", x);
        recurse_fun(x-1);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    recurse_fun(n);
}