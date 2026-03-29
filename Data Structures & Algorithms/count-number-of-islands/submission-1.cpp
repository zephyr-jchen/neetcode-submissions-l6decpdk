class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    helper(grid,i,j);
                }
                    
            }
        }
        return count;
    }
    void helper(vector<vector<char>>& grid,int r,int c){
        if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]=='0'){
            return ;
        }
        grid[r][c] = '0';
        helper(grid,r,c+1);
        helper(grid,r,c-1);
        helper(grid,r+1,c);
        helper(grid,r-1,c);
    }
};
