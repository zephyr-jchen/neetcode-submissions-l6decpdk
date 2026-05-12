class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> select;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0,res,select);
        return res;
    }
private:
    void backtrack(vector<int>& candidates, int target, int start, vector<vector<int>>& res,vector<int>& select){
        if(target == 0){
            res.push_back(select);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            if(target - candidates[i] < 0){return;}
            if(i > start && candidates[i] == candidates[i-1]){continue;}
            
            select.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],i+1,res,select);
            select.pop_back();
        }
    }
};
