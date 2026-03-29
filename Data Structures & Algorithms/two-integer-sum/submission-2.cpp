class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> preMap;
        vector<int> result;
        for(int i = 0; i<nums.size(); i++){
            if(preMap.find(target-nums[i]) != preMap.end()){
                result.push_back(preMap[target-nums[i]]);
                result.push_back(i);
                break;
            }else{
                preMap[nums[i]] = i;
            }
        }
        return result;
    }
};
