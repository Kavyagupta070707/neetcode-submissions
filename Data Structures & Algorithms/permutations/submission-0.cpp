class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int> &temp, vector<int> &b){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
        }

        for(int i=0;i<nums.size();i++){
            if(!b[i]){
                temp.push_back(nums[i]);
                b[i]=1;
                solve(nums,temp,b);
                temp.pop_back();
                b[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<int> b(nums.size(),0);

        solve(nums,temp,b);
        return ans;
    }
};
