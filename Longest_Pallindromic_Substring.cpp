/* Longest Pallindromic Substring by Abhishek Kanaujiya.This Problem was available on Leetcode. So I would Like to Share my Solution.*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        int len = 0;
        int start_ind = 0 , end_ind = 0;
        for(int g = 0 ; g < n ; g++)
        {
            for(int i = 0 , j = g ; j < n ; i++ , j++)
            {
                if(g == 0)
                   { 
                    dp[i][j] = true;
                   }
                else if(g == 1)
                {
                    if(s[i] == s[j])
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                else
                {
                    if(s[i] == s[j] && dp[i+1][j-1] == true)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                if(dp[i][j])
                {
                    if(len < g+1)
                    {
                        len = g+1;
                        start_ind = i;
                        end_ind = j;
                        cout<<i<<" "<<j<<endl;
                       // cout<<len<<" ";
                    }
                }
            }
        }
        return s.substr(start_ind , end_ind - start_ind +1);
    }
};
