#include<stdio.h>

//recursive function to find maximum element in an array
int Findmaxnumber(int array[], int index, int len)
 {
     int max;
     if(index >= len-2)
     {
         if(array[index] > array[index + 1])
             return array[index];
         else
             return array[index + 1];
     }
 
     max = Findmaxnumber(array, index + 1, len);

     if(array[index] > max)
         return array[index];
     else
         return max;
 }
 
 //Recursive function to find minimum element in the array
 int Findminnumber(int array[], int index, int len)
 {
     int min;
 
     if(index >= len-2)
     {
         if(array[index] < array[index + 1])
             return array[index];
         else
             return array[index + 1];
     }
 
     min = Findminnumber(array, index + 1, len);
 
     if(array[index] < min)
         return array[index];
     else
         return min;
 }

 void main()
 {
     int a[100],n;
     printf("enter the size of the array: ");
     scanf("%d",&n);

        for (int i = 0; i < n; i++)     
        {
        printf("enter the element at %d: ",i);
        scanf("%d",&a[i]);
        }

        int max=Findmaxnumber(a,0,n);
        int min=Findminnumber(a,0,n);

        printf("the max element is %d and the min element is %d ",max,min);
}