class Solution {
public:
    int solve(int i, int j, vector<int> &v,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(int k=i;k<=j;k++){
            int res = v[i-1]*v[k]*v[j+1] + solve(i,k-1,v,dp)+solve(k+1,j,v,dp);
            ans=max(ans,res);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+2,vector<int> (n+2,-1));
        vector<int> v;
        v.push_back(1);
        for(auto &it:nums){
            v.push_back(it);
        }
        v.push_back(1);
        return solve(1,n,v,dp);
    }
};
