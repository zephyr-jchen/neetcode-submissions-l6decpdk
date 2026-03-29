class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size();i++){
            for(int j = 0; j<board[0].size();j++){
                if(dfs(board,word,i,j,0)){
                    return true;
                }
                
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int r,int c, int index){
        if(index == word.size()){return true;}
        
        if((r<0) || (r>=board.size()) || (c<0) || (c>=board[0].size()) || board[r][c] != word[index]){
            return false;
        }
        char tmp  = board[r][c];
        board[r][c] = '#';
        bool found = dfs(board, word, r, c+1, index+1)||
                     dfs(board, word, r, c-1, index+1)||
                     dfs(board, word, r+1, c, index+1)||
                     dfs(board, word, r-1, c, index+1);
        board[r][c]  = tmp;
        return found;

    }
};

