class Solution {
    int dic[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; i++){
            dfs(board,i,0);
            dfs(board,i,cols-1);
        }
        for(int j = 0; j < cols; j++){
            dfs(board,0,j);
            dfs(board,rows-1,j);
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, int r,int c){
        int rows = board.size();
        int cols = board[0].size();
        if(r<0||c<0||r>=rows||c>=cols||board[r][c]=='X'||board[r][c]=='#')
        {return;}
        board[r][c] = '#';
        for(auto& d:dic){
            dfs(board,r+d[0],c+d[1]);
        }
    }
};
