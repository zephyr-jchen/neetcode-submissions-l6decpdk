class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int step1 = cost[0];
        int step2 = cost[1];
        int n = cost.size();
        for(int i = 2; i < n; i++){
            int step3 = min(step1,step2) + cost[i];
            step1 = step2;
            step2 = step3;
        }
        return min(step1,step2);
    }
};
