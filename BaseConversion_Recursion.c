// Program to convert decimal number to binary,octal and hexadecimal.
#include<stdio.h>
void convert(int,int);
int main()
{
    int num;
    printf("Enter any decimal number :");
    scanf("%d",&num);
    printf("Binary :");
    calc(num,2);
    printf("\nOctal :");
    calc(num,8);
    printf("\nHexadecimal :");
    calc(num,16);
    return 0;
}
void convert(int num,int base)
{
    int rem;
    if(num==0)
    {
       return ;
    }
    rem=num%base;
    calc(num/base,base);
    if(rem<10)
    {
        printf("%d",rem);
    }
    else
    {
        printf("%c",rem-10+'A');
    }
}
