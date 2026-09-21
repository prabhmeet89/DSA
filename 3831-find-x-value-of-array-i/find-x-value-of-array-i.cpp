class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for(int num : nums) {

            vector<long long> newdp(k, 0);

            int x = num % k;

            // Start a new subarray
            newdp[x] = 1;

            // Extend previous subarrays
            for(int r = 0; r < k; r++) {

                int newRemainder = (r * x) % k;

                newdp[newRemainder] += dp[r];
            }

            // Add current subarrays to answer
            for(int r = 0; r < k; r++) {
                result[r] += newdp[r];
            }

            dp = newdp;
        }

        return result;
    }
};