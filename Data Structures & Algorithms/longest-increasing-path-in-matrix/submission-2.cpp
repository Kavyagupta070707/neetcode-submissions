class Solution {
public:

    int dfs(int r, int c, vector<vector<int>>& matrix,vector<vector<int>> &dp){
        int n=matrix.size();
        int m=matrix[0].size();
        if(r>=n || c>=m) return 0;

        if(dp[r][c]!=-1) return dp[r][c];
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        int ans=0;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr<n && nr>=0 && nc<m && nc>=0 && matrix[nr][nc]>matrix[r][c]){
                ans = max(ans, 1+dfs(nr,nc,matrix,dp));
            }
        }
        return dp[r][c]= ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans, dfs(i,j,matrix,dp));
            }
        }
        return ans+1;
    }
};
