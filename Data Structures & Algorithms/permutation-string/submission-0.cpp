class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s1.size()){
            return false;
        }
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        int matches = 0;
        for(int i = 0; i < s1.size(); i++){
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(count1[i] == count2[i]){
                matches++;
            }
        }
        for(int r = s1.size(); r < s2.size(); r++){
            if(matches == 26){
                return true;
            }
            int indexR = s2[r] - 'a';
            count2[indexR]++;
            if(count1[indexR] == count2[indexR]){
                matches++;
            }else if(count1[indexR] + 1 == count2[indexR]){
                matches--;
            }
            int indexL = s2[r - s1.size()] - 'a';
            count2[indexL]--;
            if(count1[indexL] == count2[indexL]){
                matches++;
            }else if(count1[indexL] - 1 == count2[indexL]){
                matches--;
            }

        }
        return matches == 26;
    }
};
