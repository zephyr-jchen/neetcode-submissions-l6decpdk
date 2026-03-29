class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> strMap;
        for(string str:strs){
            string sortedS = str;
            sort(sortedS.begin(),sortedS.end());
            strMap[sortedS].push_back(str);
        }
        for(const auto& it:strMap){
            result.push_back(it.second);
        }
        return result;

    }
};
