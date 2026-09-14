class Solution {
   public:
    void solve(vector<int>& c, int target, int i, vector<int>& v, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }

        for (int j = i; j < c.size(); j++) {
            if (j > i && c[j] == c[j - 1]) continue;
            if (c[j] > target) break;
            v.push_back(c[j]);
            solve(c, target - c[j], j + 1, v, ans);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> v;

        solve(candidates, target, 0, v, ans);

        return ans;
    }
};