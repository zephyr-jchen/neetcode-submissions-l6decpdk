class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto& c:prerequisites){
            adj[c[1]].push_back(c[0]);
            indegree[c[0]]++;
        }
        std::queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int finish = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            finish++;
            for(int course:adj[node]){
                indegree[course]--;
                if(indegree[course] == 0){
                    q.push(course);
                }
            }
        }
        return finish == numCourses;
    }
};
