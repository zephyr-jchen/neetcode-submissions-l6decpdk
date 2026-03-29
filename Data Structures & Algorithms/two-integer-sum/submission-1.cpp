class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> newMap;
        for(int i = 0; i < nums.size(); i++){     
            int diff = target - nums[i];
            if(newMap.find(diff) != newMap.end()){
                return {newMap[diff], i};
            }
            newMap.insert({nums[i], i});
        }
        return {};
    }
};
