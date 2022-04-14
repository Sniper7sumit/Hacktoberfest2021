/*
PROBLEM STATEMENT:
Given an array nums of distinct integers,
return all the possible permutations. 
EXAMPLE:
n=3
array:
1 2 3
Answer:
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2
3 2 1
*/
//With backtracking we explore all possible arrangements
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>v;
void permutations(vector<int>&temp,vector<int>& nums,int n){
        if(temp.size()==n){
            v.push_back(temp);
            return;
        }
        for(int i=0;i!=n;i++){
            if(std::find(temp.begin(),temp.end(),nums[i])==temp.end()){
                temp.push_back(nums[i]);
                permutations(temp,nums,n);
                temp.pop_back();
            }
        }
        return;
}
vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        permutations(temp,nums,nums.size());
        return v;
}
int main(){
//input length of array    
int n;
cin>>n;    
vector<int>nums(n);
//input array
for(int i=0;i!=n;i++){
    cin>>nums[i];
}
vector<vector<int>>ans=permute(nums);
for(int i=0;i!=ans.size();i++){
    for(int j=0;j!=ans[0].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}
