#include<stdio.h>
#include<stdlib.h>

void fnDispArr(int arr[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void insertionSort(int arr[],int n){
	int i,j,temp;
	
	for(i=1;i<n;i++){
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>temp){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}

int main(){
	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	
	int arr[n];
	
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	printf("Entered array is:\n");
	fnDispArr(arr,n);
	
	insertionSort(arr,n);
	printf("Sorted array is:\n");
	fnDispArr(arr,n);
	return 0;
}
