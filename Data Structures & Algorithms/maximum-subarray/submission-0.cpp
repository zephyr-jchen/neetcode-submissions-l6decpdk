class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = nums[0], maxSum = nums[0];
        for(int i = 1; i<nums.size(); i++){
            curMax = max(nums[i], nums[i]+curMax);
            maxSum = max(maxSum, curMax);
        }
        return maxSum;
    }
};
