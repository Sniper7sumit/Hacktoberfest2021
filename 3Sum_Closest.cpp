//Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
//Return the sum of the three integers.
//You may assume that each input would have exactly one solution.
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = INT_MAX;
        int diff = INT_MAX;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<n; i++){
            int low = i+1;
            int high = n-1;
            int sum = target - nums[i];
            while(low < high){
                int two_sum = nums[low] + nums[high];
                if(abs((two_sum + nums[i]) - target) < diff){
                    diff = abs((two_sum + nums[i]) - target);
                    ans = two_sum + nums[i];
                }
                if(two_sum > sum)
                    high--;
                else if(two_sum < sum)
                    low++;
                else 
                    return (two_sum + nums[i]);
            }
            while(i + 1 < n && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};
