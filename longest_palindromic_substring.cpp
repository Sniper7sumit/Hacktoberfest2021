class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string res="";
        res+=s[0];
        int l,h,sz;
        for(int i=0 ; i<n ; i++){
            l=i,h=i+1;
            sz=0;
            while(l>=0 && h<n && s[l]==s[h]){
                l--;
                h++;
                sz+=2;
            }
            if(sz>res.size()){
                res=s.substr(l+1,sz);
            }
            sz=1;
            l=i-1;
            h=i+1;
            while(l>=0 && h<n && s[l]==s[h]){
                l--;
                h++;
                sz+=2;
            }
            if(sz>res.size()){
                res=s.substr(l+1,sz);
            }
        }
        return res;
    }
};
