// We give you a string. In string, every character have decimal value. If the decimal value of character is even then
// make the character in uppercase. Implement this by using function.
// Note - It is guaranteed that input string is always in lowercase.

#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    scanf("%s",str);
    lower_to_upper(str);
    puts(str);
}
void lower_to_upper(char str[])
{
    int len=strlen(str);
    for (int i = 0; i < len; i++)
    {
        if ( str[i]%2 ==0 )
        {
            str[i]=str[i]-32;
        }
    }
}