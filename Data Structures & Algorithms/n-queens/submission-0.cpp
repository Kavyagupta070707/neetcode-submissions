class Solution {
public:
    vector<vector<string>> ans;
    unordered_set<int> col;
    unordered_set<int> posdig;
    unordered_set<int> negdig;
    void solve(int q, int n , vector<string> &board){
        if(q==n){
            ans.push_back(board);
            return;
        }

        for(int c=0;c<n;c++){
            if(col.count(c) || posdig.count(q+c)|| negdig.count(q-c)){
                continue;
            }

            col.insert(c);
            posdig.insert(q+c);
            negdig.insert(q-c);
            board[q][c]='Q';

            solve(q+1,n,board);

            col.erase(c);
            posdig.erase(q+c);
            negdig.erase(q-c);
            board[q][c]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        solve(0,n,board);

        return ans;
    }
};
