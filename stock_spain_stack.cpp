#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int ar[], int n)
    {
       stack<int>st;
       vector<int>v(n,1);
       int t=1,t1=0;
       st.push(0);
       for(int i=1;i<n;++i)
       {
            if(ar[st.top()]>ar[i])
            {
                st.push(i);
            }else{
               while(!st.empty() && ar[i]>=ar[st.top()])
               {
                   st.pop();
                   t++;
               }
               if(st.empty())
               {
                   v[i]=i+1;
               }else{
                   v[i]=i-st.top();
               }
               
               st.push(i);
            }
       }
       return v;
    }
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}