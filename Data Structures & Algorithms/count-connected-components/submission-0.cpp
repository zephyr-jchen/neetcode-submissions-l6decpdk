class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count = n;
        vector<int> parent(n);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
        for(auto& edge:edges){
            int root1 = find(parent,edge[0]);
            int root2 = find(parent,edge[1]);
            if(root1 != root2){
                parent[root1] = root2;
                count--;
            }
        }
        return count;
    }

    int find(vector<int>& parent, int i){
        if(parent[i] == i){return i;}
        return parent[i] = find(parent,parent[i]);
    }
};
