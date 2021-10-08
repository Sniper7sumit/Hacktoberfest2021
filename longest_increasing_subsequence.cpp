// This is a Cpp code to find the length of the longest increasing subsequence of a sequence.

#include <bits/stdc++.h>
using namespace std;

int lis(int a[],int n)
{
	int is[n]={}; // stores the length of longest increasing subsequence ending with number at that index. 
	for (int i = 0; i < n; ++i)
	{
		is[i]=1; // initiating array with 1 because one subsequence of atleast length 1 ends with number at any index(That number itself).
	}
	for (int i = 0; i < n; ++i)
	{
		for(int j=i+1; j<n; ++j)
		{
			if (a[j]>a[i] && is[j]<is[i]+1)
			{
				is[j]=is[i]+1;
			}
		}
	}
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		if (is[i]>ans)
		{
			ans=is[i];
		}
	}
	return ans;
}

int main()
{
	int a[]={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	// Here the longest increasing subsequnce is {0, 2, 6, 9, 11, 15}
	cout<<"The length of longest increasing subsequence is "<<lis(a,sizeof(a)/sizeof(a[0]))<<"\n";
	return 0;
} 