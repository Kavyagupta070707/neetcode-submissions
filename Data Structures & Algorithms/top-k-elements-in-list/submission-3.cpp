class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;

        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto it:m){
            if(pq.size()==k){
                if(pq.top().first<it.second){
                    pq.pop();    
                }
            }
            if(pq.size()<k)
                pq.push({it.second,it.first});
        }

        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};
