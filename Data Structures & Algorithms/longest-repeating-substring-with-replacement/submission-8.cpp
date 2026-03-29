class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int l = 0, res = 0, max_freq = 0;
        for(int i = 0; i < s.size(); i++){
            freq[s[i]]++;
            max_freq = max(max_freq,freq[s[i]]);
            if(i - l + 1 > k + max_freq){
                freq[s[l]]--;
                l++;
            }
            res = max(res,i - l + 1);
        }
        return res;
    }
};
