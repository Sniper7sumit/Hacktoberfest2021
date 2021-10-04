/*
BY AMITESH AGRAWAL
LONGEST PALLINDROMIC SUBSTRING 
*/


#include <bits/stdc++.h>
using namespace std;


int dp[1001][1001];
string longestPalindrome(string s) {
    memset(dp,0,sizeof(dp));
    int start =0;
    int k = 1;
    for(int i=0;i<s.length();i++){
        dp[i][i] = true;
    }
    for(int i=0;i<s.length()-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1] = true;
                k=2;
                start = i;
        
    }
    }
        

    for(int i=3;i<=s.length();i++){
        for(int j=0;j<s.length() - i+1;j++){
            int l = i+j-1; 
            
            if(dp[j+1][l-1] && s[j]==s[l]){
                dp[j][l] = true;
                if(k<i){
                    k=i;
                    start = j;
                }
            }
            
        }
    }

    string ans = s.substr(start,k);

    return ans;
        
}

int main(){
    string str;
    cin>>str;

    cout<<longestPalindrome(str);
}


/*

TC : O(n^2)    where n is the length of string
SC : O(n^2)     dp table for storing answer beforehand

*/