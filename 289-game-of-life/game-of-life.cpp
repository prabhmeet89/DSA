class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> temp = board;

        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                int live = 0;

                // Check 8 neighbors
                for (int k = 0; k < 8; k++) {

                    int r = i + dr[k];
                    int c = j + dc[k];

                    if (r >= 0 && r < m &&
                        c >= 0 && c < n &&
                        temp[r][c] == 1) {

                        live++;
                    }
                }

                // Apply Game of Life rules

                if (temp[i][j] == 1) {

                    // Live cell
                    if (live < 2 || live > 3) {
                        board[i][j] = 0;
                    }
                    // if live == 2 or 3, it stays alive
                }
                else {

                    // Dead cell
                    if (live == 3) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};