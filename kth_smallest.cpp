#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v={7,10,4,3,20,15};
	priority_queue<int> maxheap;

	int k;
	cin>>k;
	for(int i=0;i<v.size();i++)
	{
		maxheap.push(v[i]);
		if(maxheap.size()>k)
			maxheap.pop();
	}
	cout<<maxheap.top()<<endl;
}
