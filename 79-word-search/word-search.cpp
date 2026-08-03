class Solution {
public:

    bool dfs(vector<vector<char>>& board, string& word,
             int i, int j, int index) {

        // Word completely found
        if (index == word.size()) {
            return true;
        }

        // Out of bounds
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size()) {
            return false;
        }

        // Current cell doesn't match
        if (board[i][j] != word[index]) {
            return false;
        }

        // Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Check 4 directions
        bool found =
            dfs(board, word, i - 1, j, index + 1) ||  // up
            dfs(board, word, i + 1, j, index + 1) ||  // down
            dfs(board, word, i, j - 1, index + 1) ||  // left
            dfs(board, word, i, j + 1, index + 1);    // right

        // Backtrack
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0]) {

                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};