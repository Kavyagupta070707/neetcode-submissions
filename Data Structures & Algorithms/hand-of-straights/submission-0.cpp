class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        int ng = n/groupSize;

        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[hand[i]]++;
        }

        sort(hand.begin(),hand.end());

        for(int i=0;i<n;i++){
            if(m[hand[i]]==0) continue;

            int st = hand[i];
            int size=1;
            m[st]--;
            while(size!=groupSize){
                if(m[st+1]==0) return 0;
                m[st+1]--;
                size++;
                st++;   
            }
        }

        return 1;
    }
};
