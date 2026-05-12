class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> select;
        sort(nums.begin(),nums.end());
        backtrack(nums,0,select,res);
        return res;
    }
private:
    void backtrack(vector<int>& nums, int start, vector<int>& select, vector<vector<int>>& res){
        res.push_back(select);
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i-1]){continue;}
            select.push_back(nums[i]);
            backtrack(nums,i+1,select,res);
            select.pop_back();
        }
    }
};
