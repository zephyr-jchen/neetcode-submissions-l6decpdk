class Solution {
    vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {      
        vector<string> res;
        if(digits.empty())return res;
        string track;
        backtrack(digits,res,0,track);
        return res;
    }
private:
    void backtrack(string& digits, vector<string>& res, int index, string& track){
        if(index == digits.size()){
            res.push_back(track);
            return;
        }
        string tmp = mapping[digits[index] - '0'];
        for(int i = 0; i < tmp.size(); i++){
            track.push_back(tmp[i]);
            backtrack(digits,res,index+1,track);
            track.pop_back();
        }
    }
};
