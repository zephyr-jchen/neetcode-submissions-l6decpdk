class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0, l = 0, r = heights.size()-1;
        while(l<r){
            int area = min(heights[l],heights[r])*(r-l);
            if(heights[l]>heights[r]){
                r--;}
            else{l++;}
            res = max(area,res);
        }
        return res;
    
    }
};
