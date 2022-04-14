// Example 1:
// Input: s = "12"
// Output: 2
// Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
// Example 2:
// Input: s = "226"
// Output: 3
// Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

#include<iostream>
#include<vector>
using namespace std;
int numDecodings(string s) {
        int n = s.size(), i;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = s[0] =='0' ? 0:1;
        
        for(i=2;i<=n; i++){
            //dp[i] = dp[i-1] +dp[i-2];
            //only the last character
            dp[i] = 0;
            if(s[i-1] != '0')
                dp[i] += dp[i-1];
            //last 2 characters
            if(s[i-2] == '1')
                dp[i] += dp[i-2];
            else if(s[i-2] <= '2' && s[i-1] <= '6')
                dp[i] += dp[i-2];
        }
        return dp[n];
    }

int main()
{
  string s;
  cin>>s;
  cout<<numDecoding(s)<<endl;
  
  return 0;
}
