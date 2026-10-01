class DSU{
    public:
    vector<int> size;
    vector<int> par;

    DSU(int n){
        
        size.resize(n);
        par.resize(n);

        for(int i=0;i<n;i++){
            size[i]=1;
            par[i]=i;
        }

    }
        int find(int node){
            if(par[node]==node) return node;

            return par[node]=find(par[node]);
        }

        void unionbysize(int u, int v){
            int pu=find(u);
            int pv=find(v);

            if(pu==pv) return;
            if(size[pu]>=size[pv]){
                par[pv]=pu;
                size[pu]+=size[pv];
            }
            else{
                par[pu]=pv;
                size[pv]+=size[pu];
            }
        }
};

class Solution {
   public:
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<int, int>>> adj;

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int dis = abs(points[i][0] - points[j][0]) +                  abs(points[i][1] - points[j][1]);
                adj.push_back({dis,{i,j}});
            }
        }
        int n = points.size();
        DSU dsu(n);
        sort(adj.begin(),adj.end());
        int ans=0;
        for(auto &it: adj){
            int dis=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(dsu.find(u)!=dsu.find(v)){
                ans+=dis;
                dsu.unionbysize(u,v);
            }
        }
        return ans;
    }
};
