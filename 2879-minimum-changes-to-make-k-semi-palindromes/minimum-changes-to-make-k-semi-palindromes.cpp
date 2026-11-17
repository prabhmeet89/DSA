
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, 0));

        // Step 1: Calculate cost of every substring
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {

                int j = i + len - 1;
                cost[i][j] = INT_MAX;

                // Try every proper divisor
                for (int d = 1; d < len; d++) {

                    if (len % d != 0) continue;

                    int changes = 0;

                    // Compare mirrored characters
                    // in each group
                    for (int r = 0; r < d; r++) {

                        int left = i + r;
                        int right = j - ((j - left) % d);

                        while (left < right) {

                            if (s[left] != s[right]) {
                                changes++;
                            }

                            left += d;
                            right -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // Step 2: DP
        vector<vector<int>> dp(
            n + 1, vector<int>(k + 1, INT_MAX / 2)
        );

        dp[0][0] = 0;

        // j = number of substrings
        for (int j = 1; j <= k; j++) {

            // i = number of characters considered
            for (int i = 2 * j; i <= n; i++) {

                // t = starting index of last substring
                for (int t = 2 * (j - 1); t <= i - 2; t++) {

                    dp[i][j] = min(
                        dp[i][j],
                        dp[t][j - 1] + cost[t][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
