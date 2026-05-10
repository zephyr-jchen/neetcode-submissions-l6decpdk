class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for(char task : tasks){
            count[task - 'A']++;
        }
        int max_count = *max_element(count.begin(),count.end());
        int max_char = 0;
        for(int c : count){
            if(c == max_count){
                max_char++;
            }
        }
        int time_total = (max_count - 1) * (n + 1) + max_char;
        return max(time_total,(int)tasks.size());

    }
};
