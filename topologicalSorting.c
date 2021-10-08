//Input : Adjacency Matrix
//Output: Order in which vertices are popped out in topological sorting

#include<stdio.h>
#include<stdlib.h>

//Topological sorting done by source removal algorithm
void topologicalSorting(int arr[10][10],int n){
	
	//in[] is the input array that keep the count of sources for each node, out[] is the output array, s[] is the stack
 	int in[n],out[n],s[n],top=-1;
	int i,j,k=0;
	
	//putting the number of source nodes in the input array
	for(i=0;i<n;i++){
		in[i]=0;
		for(j=0;j<n;j++){
			if(arr[j][i]==1)
				in[i]++;
		}
	}
	
	while(1){
		//if there is no source for the vertex then adding it to the stack and initialing the value of vertex in input array as -1
		for(i=0;i<n;i++)
			if(in[i]==0){
				s[++top]=i;
				in[i]=-1;
			}
		
		//if there are no vertex which are having 0 source then exit from the loop
		//or if the stack is empty
		if(top==-1)
			break;
			
		//popping the top element of the stack or vertex which has no source vertex
		out[k]=s[top--];
		
		for(i=0;i<n;i++){
			//if the popped vertex has any connection in the graph then decrease the source count form the input array because we are removing the vertex from the graph
			if(arr[out[k]][i]==1){
				in[i]--;
			}
		}
		
		//incrementing the value for the output array.
		k++;
	}
	
	printf("Topological sorting order is \n");
	for(i=0;i<n;i++)
		printf("%d ",out[i]+1);
}

int main(){
	int n;
	printf("Enter the number of vertices in graph: ");
	scanf("%d",&n);
	
	int arr[10][10];
	printf("Enter the adjacency matrix for the graph\n");
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
			
	topologicalSorting(arr,n);
	return 0;	
}
