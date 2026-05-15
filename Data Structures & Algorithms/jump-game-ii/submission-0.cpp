class Solution {
public:
    int jump(vector<int>& nums) {
        int current_end = 0;
        int furthest = 0;
        int jump = 0;
        for(int i = 0; i < nums.size()-1; i++){
            furthest = max(furthest,i+nums[i]);
            if(i == current_end){
                jump++;
                current_end = furthest;
            }
        }
        return jump;
    }
};
