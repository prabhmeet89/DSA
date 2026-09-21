class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);

        unordered_map<int, long long> dp, next;

        for (int num : nums) {
            int x = num % k;
            next.clear();

            // New subarray
            next[x]++;

            // Extend previous subarrays
            for (auto &[r, cnt] : dp) {
                int rem = (long long)r * x % k;
                next[rem] += cnt;
            }

            // Add to answer
            for (auto &[r, cnt] : next) {
                ans[r] += cnt;
            }

            dp.swap(next);
        }

        return ans;
    }
};