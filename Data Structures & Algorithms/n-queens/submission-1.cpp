class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        vector<bool> cols(n,false);
        vector<bool> dia1s(2*n -1,false);
        vector<bool> dia2s(2*n -1,false);
        backtrack(ans,board,cols,dia1s,dia2s,0,n);
        return ans;
    }
private:
    void backtrack(vector<vector<string>>& ans,vector<string>& board, vector<bool>& cols,vector<bool>& dia1s,vector<bool>& dia2s,int row,int n){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int col = 0; col < n; col++){
            int dia1 = row - col + n - 1;
            int dia2 = row + col;
            if(cols[col] || dia1s[dia1] || dia2s[dia2]){continue;}
            board[row][col] = 'Q';
            cols[col] = dia1s[dia1] = dia2s[dia2] = true;
            backtrack(ans,board,cols,dia1s,dia2s,row+1,n);
            board[row][col] = '.';
            cols[col] = dia1s[dia1] = dia2s[dia2] = false;
        }
        
    }

};
