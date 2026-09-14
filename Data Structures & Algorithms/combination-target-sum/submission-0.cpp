class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int target, int i, vector<int> &v){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0 || i>=nums.size()) return;

        v.push_back(nums[i]);
        solve(nums,target-nums[i],i,v);
        v.pop_back();
        solve(nums,target,i+1,v);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>v;
        solve(nums,target,0,v);
        return ans;
    }
};
