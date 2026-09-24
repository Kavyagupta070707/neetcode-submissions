class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool t1=0;
        bool t2=0;
        bool t3=0;

        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0]>target[0] || triplets[i][1]>target[1] || triplets[i][2]>target[2]) continue;

            if(triplets[i][0]==target[0]) t1=1;
            if(triplets[i][1]==target[1]) t2=1;
            if(triplets[i][2]==target[2]) t3=1;
        }

        return t1&&t2&&t3;
    }
};
