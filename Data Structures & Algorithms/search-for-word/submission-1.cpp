class Solution {
public:

    bool dfs(vector<vector<char>>& board, string &word, vector<vector<int>> &vis, int sr, int sc, int ind) {
        if(ind == word.size()) return 1;

        int n = board.size();
        int m = board[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        vis[sr][sc] = 1;

        for(int i = 0; i < 4; i++) {
            int nr = sr + dr[i];
            int nc = sc + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && board[nr][nc] == word[ind]) {
                if(dfs(board, word, vis, nr, nc, ind+1)) return true;
                // ind--;
                vis[nr][nc] = 0;
            }
        }
        vis[sr][sc] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        // dfs(board, word, vis, 0, 0, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, word, vis, i, j, 1)) return true;
                }
            }
        }

        return false;
    }
};
