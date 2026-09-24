class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ind=-1;
        int fuel=0;

        for(int i=0;i<gas.size();i++){
            fuel+=(gas[i]-cost[i]);
        }
        int st=0;
        if(fuel<0) return -1;
        
        int s=0;

        for(int i=0;i<gas.size();i++){
            s+=(gas[i]-cost[i]);

            if(s<0){
                s=0;
                st=i+1;
            }
        }

        return st;

    }
};
