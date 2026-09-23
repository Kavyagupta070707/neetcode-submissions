class Solution {
public:
    vector<vector<string>> ans;
    bool isPal(string s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return 0;

            l++;
            r--;
        }
        return 1;
    }
    void solve(string &s, vector<string> &v, int i){
        if(i>=s.size()){
            ans.push_back(v);
            return;
        }

        for(int j=i;j<s.size();j++){
            if(isPal(s,i,j)){
                string str = s.substr(i,j-i+1);
                v.push_back(str);
                solve(s,v,j+1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        solve(s,v,0);
        return ans;
    }
};
