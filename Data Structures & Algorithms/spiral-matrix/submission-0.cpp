class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        int top = 0, left = 0, bottom = matrix.size()-1, right = matrix[0].size()-1;
        while(true){
            for(int i = left; i<=right; i++){res.push_back(matrix[top][i]);}
            if(++top>bottom){break;}
            
            for(int j = top; j<=bottom; j++){res.push_back(matrix[j][right]);}
            if(--right<left){break;}

            for(int m = right; m>=left; m--){res.push_back(matrix[bottom][m]);}
            if(--bottom<top){break;}

            for(int n = bottom; n>=top; n--){res.push_back(matrix[n][left]);}
            if(++left>right){break;}
        }
        return res;
    }
};
