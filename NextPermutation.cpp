//Next Permutations
//Find next greater number with same set of digits


#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr)
    {
        //using inbuilt function
        vector<int> ans(arr);
        next_permutation(ans.begin(), ans.end());
        if(ans != arr)
            return ans;
        else
        {
            //if the current permutation is the last permutation, then return sorted order
            sort(ans.begin(), ans.end());
            return ans;
        }
    }
};



int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  