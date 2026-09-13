class Solution {
public:
    int solve(int i, int j, string &s1, string &s2,vector<vector<int>> &dp){
        if(i>=s1.size()){
            int rem=s2.length()-j;
            return max(0,rem);
        }
        if(j>=s2.size()){
            int rem = s1.size()-i;
            return max(0,rem);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        if(s1[i]==s2[j]){
            ans = min(ans,solve(i+1,j+1,s1,s2,dp));
        }
        else{
            int ins = 1+solve(i,j+1,s1,s2,dp);
            int del = 1+solve(i+1,j,s1,s2,dp);
            int rep = 1+solve(i+1,j+1,s1,s2,dp);
            ans=min({ans,ins,del,rep});
        }
        return dp[i][j]= ans;

    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int> (word2.size()+1,-1));
        return solve(0,0,word1,word2,dp);
    }
};
