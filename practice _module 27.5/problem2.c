//You are given a positive integer n. The next line will contain n positive integers .Now calculate the total sum in
// the following way –
// >> add the last digit of every integers
// Implement it using recursion.

#include <stdio.h>
int fun(int n)
{
  if (n > 10)
  {
    fun(n %= 10);
  }
  else
    return n;
}
int main()
{
  int n;
  scanf("%d", &n);
  int ara[n];
  int sum=0;
  for (int i = 0; i < n ; i++)
  {
    scanf("%d",&ara[i]);
    sum+=fun(ara[i]);
    printf("%d \n",sum);
  }
  
//   printf("%d \n",fun(n));
  return 0;
}