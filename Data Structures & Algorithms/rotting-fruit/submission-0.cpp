class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dic[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> pq;
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    pq.push({i,j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int time = 0;
        while(!pq.empty()){
            int num = pq.size();
            bool rotten = false;
            for(int n = 0; n < num; n++){
                pair<int,int> p = pq.front();
                pq.pop();
                int r = p.first;
                int c = p.second;
                for(int m = 0; m < 4; m++){
                    int nr = r + dic[m][0];
                    int nc = c + dic[m][1];
                    if(nc>=0 && nr>=0 && nr<rows && nc<cols&&grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        pq.push({nr,nc});
                        rotten = true;
                        fresh--;
                    }
                }
            }
            if(rotten)time++;
            
        }
        if(fresh == 0){
            return time;
        }else{
            return -1;
        }
    }
};
