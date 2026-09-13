class Solution {
public:
    int solve(int i, int j,string &s, string &t,vector<vector<int>> &dp){
        if(j>=t.size()) return 1;

        if(i>=s.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int tk=0;

        if(s[i]==t[j]){
            tk = solve(i+1,j+1,s,t,dp);
        } 
        int nt = solve(i+1,j,s,t,dp);

        return dp[i][j]= tk+nt;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1,-1));
        return solve(0,0,s,t,dp);
    }
};
