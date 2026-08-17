class Solution {
public:

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        // Prefix sum
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        // dp[l][r] = maximum score from l to r
        vector<vector<long long>> dp(
            n, vector<long long>(n, 0)
        );

        // Length of subarray
        for (int len = 2; len <= n; len++) {

            for (int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                // Try every split
                for (int k = l; k < r; k++) {

                    // Sum of left part
                    long long left =
                        prefix[k + 1] - prefix[l];

                    // Sum of right part
                    long long right =
                        prefix[r + 1] - prefix[k + 1];

                    if (left < right) {

                        dp[l][r] = max(
                            dp[l][r],
                            left + dp[l][k]
                        );

                    }
                    else if (left > right) {

                        dp[l][r] = max(
                            dp[l][r],
                            right + dp[k + 1][r]
                        );

                    }
                    else {

                        dp[l][r] = max(
                            dp[l][r],
                            left + max(
                                dp[l][k],
                                dp[k + 1][r]
                            )
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};