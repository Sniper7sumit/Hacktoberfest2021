/ { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {

        int n=str.length();
        int temp,ans=0;
        int i=n-1,s=0;
        if(str[0]=='-')
            s=1;
        
        while(i>=s){
            
            if(str[i]-'0'>=0 &&str[i]-'0'<=9){
                temp=(str[i]-'0');
                ans+=(pow(10,n-i-1)*temp);
            }
            else
                return -1;
            i--;
        }
        if(str[0]=='-')
            ans=ans*-1;
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends
