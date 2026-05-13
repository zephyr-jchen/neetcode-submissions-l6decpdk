class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    res = max(helper(grid,i,j),res);
                }             
            }
        }
        return res;
    }
private:
    int helper(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0){
            return 0;
        }
        int area = 1;
        grid[r][c] = 0;
        area += helper(grid,r-1,c);
        area += helper(grid,r+1,c);
        area += helper(grid,r,c-1);
        area += helper(grid,r,c+1);
        return area;

    }
};
