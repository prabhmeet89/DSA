class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        vector<long long> down(n, 0);
        down[0] = 1;

        for (int i = 0; i < m; i++) {
            long long right = 0;

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    swap(right, down[j]);
                }
                else {
                    long long total = (right + down[j]) % MOD;
                    right = total;
                    down[j] = total;
                }
            }
        }

        return down[n - 1];
    }
};