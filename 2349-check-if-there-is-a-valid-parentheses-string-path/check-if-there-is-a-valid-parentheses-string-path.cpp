class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int len = m + n - 1;

        // Valid parentheses string ki length even honi chahiye
        if (len % 2 != 0)
            return false;

        // Start '(' hona chahiye
        if (grid[0][0] == ')')
            return false;

        // dp[j][balance]
        vector<vector<bool>> dp(n, vector<bool>(len + 1, false));

        dp[0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                // Previous UP state ko save karo
                vector<bool> up = dp[j];

                // Current cell ke liye fresh state
                fill(dp[j].begin(), dp[j].end(), false);

                int change = (grid[i][j] == '(') ? 1 : -1;

                for (int bal = 0; bal <= i + j + 1; bal++) {

                    int prev = bal - change;

                    if (prev < 0)
                        continue;

                    // UP se aa sakte hain
                    if (i > 0 && up[prev])
                        dp[j][bal] = true;

                    // LEFT se aa sakte hain
                    if (j > 0 && dp[j - 1][prev])
                        dp[j][bal] = true;
                }
            }
        }

        // End par balance 0 hona compulsory hai
        return dp[n - 1][0];
    }
};