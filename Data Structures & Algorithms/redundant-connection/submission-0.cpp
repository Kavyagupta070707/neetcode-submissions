class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1,0);
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            indegree[u]++;
            indegree[v]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &it: adj[node]){
                indegree[it]--;
                if(indegree[it]==1){
                    q.push(it);
                }
            }
        }

        for(int i=n-1;i>=0;i--){
            int u=edges[i][0];
            int v=edges[i][1];
            if(indegree[u]==2 && indegree[v]==2){
                return {u,v};
            }
        }
        return {};
    }
};
