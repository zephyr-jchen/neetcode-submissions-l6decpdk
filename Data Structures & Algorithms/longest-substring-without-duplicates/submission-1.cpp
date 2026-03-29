class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, l = 0;
        unordered_map<char,int> Smap;
        for(int r = 0; r < s.size(); r++){
            if(Smap.find(s[r]) != Smap.end()){
                l = max(Smap[s[r]] + 1,l);
            }
            Smap[s[r]] = r;
            res = max(res,r-l+1);
        }
        return res;
    }
};
