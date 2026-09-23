class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int, pair<int,int>>>> pq;

        vector<vector<int>> dis(n,vector<int>(m,1e9));
        pq.push({grid[0][0],{0,0}});
        dis[0][0]=grid[0][0];

        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};

        while(!pq.empty()){
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(r==n-1 && c==m-1) return dis[r][c];
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m  ){
                    int t = max(d,grid[nr][nc]);

                    if(t<dis[nr][nc]){
                        dis[nr][nc]=t;
                        pq.push({t,{nr,nc}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};
