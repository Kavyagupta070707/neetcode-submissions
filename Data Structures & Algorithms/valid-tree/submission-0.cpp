class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<pair<int,int>> q;

        q.push({0,0});
        vis[0]=1;
        int cnt=0;
        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            cnt++;
            for(auto &it:adj[node]){
                if(!vis[it]){
                    q.push({it,node});
                    vis[it]=1;
                }
                else{
                    if(it!=par) return false;
                }
            }
        }
        if(cnt!=n) return 0;
        return true;
    }
};
