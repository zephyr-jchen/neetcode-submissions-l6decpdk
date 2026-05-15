class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n,INT_MAX);
        prices[src] = 0;
        for(int i = 0; i <= k; i++ ){
            vector<int> tmp = prices;
            for(auto& f:flights){
                int f1 = f[0];
                int f2 = f[1];
                int price = f[2];
                if(prices[f1] == INT_MAX){continue;}
                tmp[f2] = min(tmp[f2],prices[f1] + price);
            }
            prices = tmp;
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
        
    }
};
