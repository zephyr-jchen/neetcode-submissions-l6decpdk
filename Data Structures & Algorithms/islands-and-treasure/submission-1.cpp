class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int dic[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> pq;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0){
                    pq.push({i,j});
                }
            }
        }
        while(!pq.empty()){
            pair<int,int> p = pq.front();
            pq.pop(); 
            int r = p.first;
            int c = p.second;
            for(int i = 0; i < 4; i++){
                int nr = r + dic[i][0];
                int nc = c + dic[i][1];
                if(nr>=0 && nc>=0 && nr<rows && nc<cols && grid[nr][nc]==2147483647){
                    grid[nr][nc] = grid[r][c] + 1;
                    pq.push({nr,nc});
                }
                
            }
            

        }
    }

};
