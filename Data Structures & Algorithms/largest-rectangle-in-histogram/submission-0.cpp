class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n);
        vector<int> nse(n);

        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) pse[i]=-1;
            else pse[i]= st.top();

            st.push(i);
        }
        stack<int> st2;

        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && heights[st2.top()]>=heights[i]){
                st2.pop();
            }
            if(st2.empty()) nse[i]=n;
            else nse[i]= st2.top();

            st2.push(i);
        }
        int ans =0;
        for(int i=0;i<n;i++){
            int l=pse[i]+1;
            int r=nse[i]-1;

            int area = heights[i]*(r-l+1);
            ans=max(ans,area);
        }
        return ans;
    }
};
