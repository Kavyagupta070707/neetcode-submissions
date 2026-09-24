class Solution {
public:
    double solve(double x, int p){
        if(p==0) return 1.0;
        if(p==1) return x;
        double half =solve(x,p/2);
        if(p%2==0){
            return half * half;
        }
        else return half * half * x;
    }
    double myPow(double x, int n) {
        if(x==1 || x==0) return x;

        if(x==-1){
            if(n%2==0) return 1.0;

            return -1.0;
        }
        long long p=abs(n);

        double ans = solve(x,p);

        if(n<0) return 1.0/ans;

        return ans;
    }
};
