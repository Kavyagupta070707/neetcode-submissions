class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;

        for(auto s: strs){
            vector<int> c(26,0);

            for(auto ch: s){
                c[ch-'a']++;
            }
            string key=s;
           sort(key.begin(),key.end());

            
            m[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it: m){
            ans.push_back(it.second);
        }
        return ans;
    }
};
