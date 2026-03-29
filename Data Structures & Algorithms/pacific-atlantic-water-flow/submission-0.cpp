class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> canReachA(rows,vector<bool>(cols,false));
        vector<vector<bool>> canReachP(rows,vector<bool>(cols,false));
        for(int i = 0;i<rows;i++){
            dfs(heights,canReachP,i,0);
            dfs(heights,canReachA,i,cols-1);
        }
        for(int j = 0;j<cols;j++){
            dfs(heights,canReachP,0,j);
            dfs(heights,canReachA,rows-1,j);
        }
        vector<vector<int>> res;
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(canReachP[i][j]&&canReachA[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& visited,int r,int c){
        visited[r][c] = true;
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for(auto& d:dirs){
            int nr = r + d[0];
            int nc = c + d[1];
            if(nr<0||nr>=heights.size()||nc<0||nc>=heights[0].size()){continue;}
            if(!visited[nr][nc] && heights[nr][nc]>=heights[r][c]){
                dfs(heights,visited,nr,nc);
            }
        }
    }
};
