class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> track;
        backtrack(s,0,res,track);
        return res;
    }
private:
    void backtrack(string& s, int start, vector<vector<string>>& res,vector<string>& track){
        if(start == s.size()){res.push_back(track);}
        for(int i = start; i < s.size(); i++){
            if(!isPal(start,i,s)){continue;}
            track.push_back(s.substr(start,i - start + 1));
            backtrack(s,i+1,res,track);
            track.pop_back();
        }
    }

    bool isPal(int l, int r, string& s){
        while(l < r){
            if(s[l] != s[r]){return false;}
            l++;
            r--;
        }
        return true;
    }
};
