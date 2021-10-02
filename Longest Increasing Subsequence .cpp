// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].



// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
  
  
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            auto it=lower_bound(res.begin(),res.end(),nums[i]);
            if(it==res.end())res.push_back(nums[i]);
            else *it=nums[i];
        }
        return res.size();
    }
};
