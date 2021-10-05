#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
int *multiply(int A[], int B[], int m, int n)
{
    int *prod = (int *)malloc((m + n - 1) * sizeof(int));

    for (int i = 0; i < m + n - 1; i++)
        prod[i] = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            prod[i + j] += A[i] * B[j];
    }

    return prod;
}
int *addition(int A[],int B[],int m,int n)
{
    int *sum=(int*)malloc(max(m,n)*sizeof(int));
    for (int i = 0; i < min(m,n); i++)
    {
        sum[i]=A[i]+B[i];
    }
    for (int i = min(m,n); i < max(m,n); i++)
    {
        if (m>n)
            sum[i]=A[i];
        else if (m==n)
            break;
        else
            sum[i]=B[i];
    }
    return sum;
    
}
void printPoly(int poly[], int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        printf("%d", poly[i]);
        if (i != 0)
            printf("x^%d", i);
        if (i != 0)
            printf(" + ");
    }
}
int main()
{
    int A[] = {5, 0, 10, 6};
    int B[] = {1, 2, 4};
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);

    printf("First polynomial is :");
    printPoly(A, m);
    printf("\nSecond polynomial is :");
    printPoly(B, n);
    int *sum = addition(A, B, m, n);
    printf("\nSum of polynomial is :");
    printPoly(sum, max(m,n));
    int *prod = multiply(A, B, m, n);
    printf("\nProduct polynomial is :");
    printPoly(prod, m + n - 1);
    return 0;
}
