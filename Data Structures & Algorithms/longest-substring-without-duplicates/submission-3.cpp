class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> v;
        
        int l=0;
        int ans=0;
        for(int r=0;r<s.length();r++){
            v[s[r]]++;

            while(v[s[r]]>1){
                v[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
