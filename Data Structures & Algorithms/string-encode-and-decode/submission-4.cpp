class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(const auto& str : strs){
            res += to_string(str.size()) + '#' + str;
        }
        return res;

    }

    vector<string> decode(string s) {
        vector<string> de_res;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){ //read the length of number
                j++;
            }
            int length = stoi(s.substr(i, j-i));
            i = j + 1;
            de_res.push_back(s.substr(i, length));
            i += length;

        }
        return de_res;

    }
    
};
