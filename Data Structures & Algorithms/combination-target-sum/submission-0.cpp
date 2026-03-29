class Solution {
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        backtracking(nums,target,0);
        return res;
    }

    void backtracking(vector<int>& nums, int target, int start){
        if(target == 0){
            res.push_back(path);
            return;
        }
        for(int i = start; i<nums.size(); i++){
            if(target - nums[i] < 0){return;}
            path.push_back(nums[i]);
            backtracking(nums,target - nums[i],i);
            path.pop_back();
        }
        return;
    }
    
};
