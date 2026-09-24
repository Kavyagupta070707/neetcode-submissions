class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c=0;
        int n=digits.size();
        int  d = digits[n-1]+1;
        c=d/10;
        digits[n-1]=d%10;
        // cout<<c;
        int i=n-2;
        while(i>=0 && c==1){
            int  d = digits[i]+c;
            c=d/10;
            digits[i]=d%10;
            i--;
        }

        if(c==1) digits.insert(digits.begin(),c);

        return digits;
    }
};
