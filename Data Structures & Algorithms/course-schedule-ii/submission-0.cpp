class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        // vector<int> vis(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;
        int c=0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                // vis[i]=1;
                c++;
            }
        }
        vector<int> ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto &it: adj[node]){
                
                    indegree[it]--;
                    if(indegree[it]==0){
                        q.push(it);
                        // vis[it]=1;
                        c++;
                    }
                
            }
        }
        if(c!=numCourses) return {};

        return ans;
    }
};
