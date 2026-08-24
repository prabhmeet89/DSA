class Solution {
public:
    long long stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefix(n);

        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // When only 2 stones are left,
        // the player MUST take both.
        vector<long long> dp(n);

        dp[n - 2] = prefix[n - 1];

        for (int i = n - 3; i >= 0; i--) {
            dp[i] = max(
                dp[i + 1],
                prefix[i + 1] - dp[i + 1]
            );
        }

        return dp[0];
    }
};