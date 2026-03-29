class Solution {
private:
    int expand(string& s, int left, int right){
        while(left>=0 && right<s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
public:
    string longestPalindrome(string s) {
        int max_length = 0;
        int start = 0;
        for(int i=0; i<s.size(); i++){
            int odd_length = expand(s,i,i);
            int even_length = expand(s,i,i+1);
            int cur_max = max(odd_length,even_length);
            if(cur_max > max_length){
                max_length = cur_max;
                start = i - (max_length-1)/2;
            }
        }
        return s.substr(start,max_length);
        
    }
};
