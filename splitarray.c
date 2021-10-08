#include<stdio.h>
int main(){

    int m[5][5];
    int n;
    int i,j;

    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int t=0;

    if(n%2!=0)
        printf("enter even numbers");
    int arr[n];
    int tmp1=0;
    printf("enter elements");

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

     for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            *(*(m+i)+j)=0;
        }
    }

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            *(*(m+i)+j)=arr[t];
            tmp1++;
            t++;
            if(tmp1>=(n/2))
            break;
        }
        if(tmp1>=(n/2))
            break;

    }

    tmp1=n;
    t=n-1;

    for(i=4;i>=0;i--)
    {
        for(j=4;j>=0;j--)
        {
            *(*(m+i)+j)=arr[t];
            tmp1--;
            t--;
            if(tmp1<=(n/2))
            break;
        }
        if(tmp1<=(n/2))
            break;
    }

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d ",*(*(m+i)+j));
        }
        printf("\n");
    }


    return 0;

}

