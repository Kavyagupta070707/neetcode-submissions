class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            m[s[i]]=i;
        }
        int l=0;
        int ind=-1;
        for(int r=0;r<s.size();r++){
            ind=max(ind,m[s[r]]);

            if(r==ind){
                ans.push_back(r-l+1);
                l=r+1;
            }

        }

        return ans;

    }
};
