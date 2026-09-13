class Solution {
public:
    int solve(int i, vector<int>& nums,int sum, int target,vector<vector<int>> &dp, int t){
        if(i>=nums.size()){
            if(sum==target){
                return 1;
            }
            return 0;
        }
        if(dp[i][sum+t]!=INT_MIN) return dp[i][sum+t];
        

        int p = solve(i+1,nums,sum+nums[i],target,dp,t);
        int m = solve(i+1,nums,sum-nums[i],target,dp,t);

        return dp[i][sum+t]=p+m;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size(),vector<int>(2*sum+1,INT_MIN));
        return solve(0,nums,0,target,dp,sum);
    }
};
