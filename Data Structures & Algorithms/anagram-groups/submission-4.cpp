class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> strMap;
        for(string str:strs){
            vector<int> count(26,0);
            for(char c:str){
                count[c - 'a']++;
            }
            string key;
            for(int i = 0; i<26; i++){
                key += '#' + to_string(count[i]);
            }
            strMap[key].push_back(str);
        }
        for(const auto& it:strMap){
            result.push_back(it.second);
        }
        return result;

    }
};
