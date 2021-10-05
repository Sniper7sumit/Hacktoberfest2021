//@sidhartha8011

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:

vector<string>find_permutation(string S)
		{

          vector<string>rans;
		   sort(S.begin(), S.end());

            do {
                rans.push_back(S);
                } 
            while (next_permutation(S.begin(), S.end()));

		   return rans; 
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
