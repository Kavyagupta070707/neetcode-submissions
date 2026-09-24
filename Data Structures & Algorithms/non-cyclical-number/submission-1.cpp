class Solution {
   public:
    int solve(int n) {
        int s = 0;

        while (n != 0) {
            int d = (n % 10);
            s += (d*d);
            n /= 10;
        }
        return s;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);
        while (true) {
            int sum = solve(n);
            if (sum == 1) return 1;
            if (s.count(sum)) return false;
            s.insert(sum);
            n=sum;
        }
    }
};
