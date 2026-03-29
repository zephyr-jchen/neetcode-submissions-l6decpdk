class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> Smap;
        int l = 0, res = 0;
        for(int i = 0; i < s.size(); i++){
            if(Smap.find(s[i]) != Smap.end()){
                l = max(l, Smap[s[i]] + 1);
            }
            Smap[s[i]] = i;
            res = max(res, i - l + 1);
        }
        return res;
    }
};
