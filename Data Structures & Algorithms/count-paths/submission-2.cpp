class Solution {
public:
    int solve(int i, int j, int m, int n){
        if(i==m-1 && j==n-1) return 1;

        if(i>=m || j>=n) return 0;

        int r = solve(i,j+1,m,n);
        int d = solve(i+1,j,m,n);

        return r+d;
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n,0));

        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    dp[i][j]=1;
                    continue;
                }

                int r = dp[i][j-1];
                int d = dp[i-1][j];

                dp[i][j]=r+d;

            }
        }
        return dp[m-1][n-1];
    }
};
