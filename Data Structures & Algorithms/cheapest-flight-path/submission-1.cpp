class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int d=flights[i][2];

            adj[u].push_back({v,d});
        }

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>
        ,greater<pair<int,pair<int,int>>>> pq;
        vector<int> dist(n,1e9);
        dist[src]=0;
        pq.push({0,{0,src}});

        while(!pq.empty()){
            int stops = pq.top().first;
            int node = pq.top().second.second;
            int dis = pq.top().second.first;

            pq.pop();

            if(stops>k) continue;

            // if(node==n-1) return dist[node];

            for(auto &it:adj[node]){
                int ne=it.first;
                int d=it.second;

                if(d+dis<dist[ne]){
                    dist[ne]=d+dis;
                    pq.push({stops+1,{dist[ne],ne}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};
