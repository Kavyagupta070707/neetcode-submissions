class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        

        for(int i=0;i<nums.size();i++){
            int target = 0-nums[i];

            int l=i+1;
            int r=nums.size()-1;

            while(l<r){
                if(nums[l]+nums[r]==target){
                    s.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;  
                }
                else if(nums[l]+nums[r]<target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }

        vector<vector<int>> ans(s.begin(),s.end());
        // for(auto it: s){
        //     ans.push_back(it);
        // }
        return ans;
    }
};
