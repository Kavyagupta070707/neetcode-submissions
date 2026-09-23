class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        while(!q.empty()){
            string w = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(w==endWord) return cnt;
            
            for(int i=0;i<w.size();i++){
                for(char c ='a';c<='z';c++){
                    char t=w[i];
                    w[i]=c;
                    if(s.count(w)){
                        q.push({w,cnt+1});
                        s.erase(w);
                    }
                    w[i]=t;
                }
            }
        }
        return 0;
    }
};
