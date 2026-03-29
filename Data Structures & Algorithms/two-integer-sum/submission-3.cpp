class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> preMap;
        for(int i = 0; i<nums.size(); i++){
            if(preMap.find(target-nums[i]) != preMap.end()){
                return {preMap[target-nums[i]],i};
            }else{
                preMap[nums[i]] = i;
            }
        }
        return {};
    }
};
