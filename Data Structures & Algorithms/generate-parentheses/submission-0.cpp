class Solution {
public:
vector<string> ans;
    void solve(int n, int open, int close, string str) {
        if(str.length() > 2*n || open > n || close > n || open < close) return;
        if(open == n && close == n) {
            ans.push_back(str);
            return;
        }

            str += '(';
            solve(n, open+1, close, str);
            str.pop_back();
            str += ')';
            solve(n, open, close+1, str);
    }

    vector<string> generateParenthesis(int n) {
        solve(n, 0, 0, "");
        return ans;
    }
};
