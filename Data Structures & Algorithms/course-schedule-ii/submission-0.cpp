class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> res;
        for(auto& course : prerequisites){
            adj[course[1]].push_back(course[0]);
            indegree[course[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int current = q.front();
            res.push_back(current);
            q.pop();
            for(int nextCourse : adj[current]){
                indegree[nextCourse]--;
                if(indegree[nextCourse] == 0){
                    q.push(nextCourse);
                }
            }
        }
        if(res.size() == numCourses){
            return res;
        }else{
            return {};
        }


    }
};