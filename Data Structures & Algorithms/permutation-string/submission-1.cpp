class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return 0;
        }
        unordered_map<char,int> m;

        for(auto &c:s1){
            m[c]++;
        }
        int cnt=m.size();
        for(int i=0;i<s1.size();i++){
            if(m.count(s2[i])){
                m[s2[i]]--;
                if(m[s2[i]]==0){
                    cnt--;
                }
            }
        }
        if(cnt==0) return 1;
        int l=0;
        for(int r=s1.size();r<s2.size();r++){
            if(m.count(s2[l])){
                m[s2[l]]++;
                if(m[s2[l]]==1) cnt++;
            }
            l++;
            if(m.count(s2[r])){
                m[s2[r]]--;
                if(m[s2[r]]==0){
                    cnt--;
                }
            }
            if(cnt==0) return 1;
        }
        return 0;
    }
};
