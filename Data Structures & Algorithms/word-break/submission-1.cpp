class Solution {
public:
    bool solve(string s,  unordered_map<string,int> &m, int i, vector<int> &dp){
        if(i==s.size()) return 1;
        if(dp[i]!=-1) return dp[i];

        for(int j=i;j<s.size();j++){
            string str = s.substr(i,j-i+1);
            if(m.count(str)){
                if(solve(s,m,j+1,dp)){
                    return dp[i]=1;
                }
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> m;
        for(auto &s: wordDict){
            m[s]++;
        }
        vector<int> dp(s.size(),-1);
        return solve(s,m,0,dp);
    }
};
