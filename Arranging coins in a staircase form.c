#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,k,n,m,l;
    printf("Enter the number of coins you have: ");
    scanf("%d", &n);
    m=n;
    for(i=1;i<n;i++)
    {
        if(m>=0)
        {
            m=m-i;
            k=i;
        }
        else
        break;
    }
    for(i=1;i<k;i++)
    {
        printf("\n");
        for(j=1;j<=i;j++)
        printf("O ");
    }
    l=0;
    {
        for(i=1;i<k;i++)
        l=l+i;
    }
    l=n-l;
    if(l!=0)
    {
        printf("\n");
        for(i=1;i<=l;i++)
        printf("O ");
        printf("\n\nno. of lines printed= %d",k);
        printf("\nlast line only contains %d no coins",l);
	}
    else
        printf("\n no. of lines printed= %d",k);
        return 0;
}
