class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size()+1);// n 是数组长度，频率范围是 0 到 n，所以需要 n + 1 个位置
        unordered_map<int,int> count;
        vector<int> res;
        for(int num:nums){
            count[num]++;
        }
        for(const auto& it:count){
            bucket[it.second].push_back(it.first);
        }
        for(int i = bucket.size()-1; i>0; i--){
            for(int n : bucket[i]){
                res.push_back(n);
                if(res.size() == k){return res;}
            }
        }
        return res;
    }
};
