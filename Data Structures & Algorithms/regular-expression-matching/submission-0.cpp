class Solution {
public:
    bool solve(int i,int j, string &s, string &p,vector<vector<int>> &dp){
        if(i>=s.size() && j>=p.size()) return 1;
        if(j>=p.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        bool match = (i<s.size()) && (s[i]==p[j] || p[j]=='.');

        if(j+1<p.size() && p[j+1]=='*'){
            bool c1 = solve(i,j+2,s,p,dp);
            bool c2=0;
            if(match){
                c2 = solve(i+1,j,s,p,dp);
            }
            return dp[i][j]= c1||c2;
        }
        if(match){
            return dp[i][j]= solve(i+1,j+1,s,p,dp);
        }
        return dp[i][j]=0;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1,-1));
        return solve(0,0,s,p,dp);
    }
};
