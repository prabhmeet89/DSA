class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int x = num % k;

            vector<long long> next(k, 0);

            // New subarray
            next[x]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] == 0) continue;

                next[(long long)r * x % k] += dp[r];
            }

            // Add to answer
            for (int r = 0; r < k; r++) {
                ans[r] += next[r];
            }

            dp.swap(next);
        }

        return ans;
    }
};