class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string track = "";
        backtrack(n,n,res,track);
        return res;
    }
private:
    void backtrack(int left, int right, vector<string>& res, string& track){
        if(left == 0 && right == 0){
            res.push_back(track);
        }
        if(left > 0){
            track.push_back('(');
            backtrack(left-1,right,res,track);
            track.pop_back();
        }
        if(right > left){
            track.push_back(')');
            backtrack(left,right-1,res,track);
            track.pop_back();
        }
    }
};
