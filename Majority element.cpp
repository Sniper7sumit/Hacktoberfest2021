https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int c=0,res=0;
        for(int i=0;i<nums.size();i++){
            if(c==0){
                res=nums[i];
            }
            if(nums[i]==res){
                c+=1;
            }
            else{
                c-=1;
            }
        }
        return res;
    }
};
