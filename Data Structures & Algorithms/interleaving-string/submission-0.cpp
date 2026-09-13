class Solution {
public:
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3,vector<vector<int>> &dp){
        if(k==s3.size()){
            return (i==s1.size() && j==s2.size());
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(i<s1.size() && s1[i]==s3[k]){
            if(solve(i+1,j,k+1,s1,s2,s3,dp)){
                return dp[i][j]=1;
            }
        }

        if(j<s2.size() && s2[j]==s3[k]){
            if(solve(i,j+1,k+1,s1,s2,s3,dp)){
                return dp[i][j]= 1;
            }
        }

        return dp[i][j]= 0;
    }

    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size()+1,vector<int> (s2.size()+1,-1));
        return solve(0,0,0,s1,s2,s3,dp);
    }
};
