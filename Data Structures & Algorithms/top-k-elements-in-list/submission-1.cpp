class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        for(int num : nums){
            cnt[num]++;
        }
        vector<vector<int>> bucket(nums.size()+1);
        for(const auto& [k,v] : cnt){
            bucket[v].push_back(k);
        }
        vector<int> res;
        for(int i = nums.size(); i>0 && res.size()<k; i--){
            for(int n : bucket[i]){
                res.push_back(n);
                if(res.size() == k){break;}
            }
        }
        return res;
    }
};
