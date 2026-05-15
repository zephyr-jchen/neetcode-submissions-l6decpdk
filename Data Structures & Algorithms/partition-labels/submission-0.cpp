class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26,0);
        for(int i = 0; i < s.size(); i++){
            last[s[i] - 'a'] = i;
        }
        int furthest = 0;
        int start = 0;
        vector<int> res;
        for(int i = 0; i < s.size(); i++){
            furthest = max(furthest,last[s[i]-'a']);
            if(i == furthest){
                res.push_back(i-start+1);
                start = i+1;
            }
        }
        return res;
    }
};
