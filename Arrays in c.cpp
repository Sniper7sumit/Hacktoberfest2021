#include <stdio.h>
#define  MAX 50
int main()
{
    int a[MAX][MAX],b[MAX][MAX],product[MAX][MAX];
    int arrows, acolumns, brows,bcolomns;
    int i,j,k;
    int sum =0;

    printf("enter rows and columns of a: ");
    scanf("%d %d",&arrows ,&acolumns);

    printf("enter elements matrix a:\n");
    for(i=0; i<arrows; i++)
    {
        for(j=0; j<acolumns; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("enter rows and columns b: ");
    scanf("%d %d", &brows, &bcolomns);

    if(brows !=acolumns)
    {
        printf("error not acptd");
    }
    else
    {
        printf("enter element of matrix b: \n");
        for(i=0; i<brows; i++)
        {
            for(j=0; j<bcolomns; j++)
                {
                    scanf("%d", &b[i][j]);
                }

        }

        }
        printf("\n");
        for(i=0; i<arrows; i++)
        {
            for(j=0; j<bcolomns; j++)
            {
                for(k=0; k<brows; k++)
                {
                    sum += a[i][k] * b[k][j];
                }
                product[i][j] =sum;
                sum=0;
            }
        }



        printf("resultant matrix\n");
        for(i=0; i<arrows ; i++)
        {
            for(j=0; j<bcolomns; j++)
            {
                printf("%d  ", product[i][j]);

            }
            printf("\n");


        }
        return 0;
    }
