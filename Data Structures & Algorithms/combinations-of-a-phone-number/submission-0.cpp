class Solution {
public:
    vector<string> ans;
    void dfs(string &digits, string &str, vector<vector<char>> &adj, int i){
        if(str.size()==digits.size()){
            ans.push_back(str);
            return;
        }
        if(i>=digits.size()) return;

        for(auto &it: adj[digits[i]-'0']){
            str+=it;
            dfs(digits, str, adj, i+1);
            str.pop_back();  
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> adj = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

        if(digits.size()==0) return {};

        for(auto &it: adj[digits[0]-'0']){
            string str="";
            str+=it;
            dfs(digits, str, adj,1);
        }

        return ans;
    }
};
