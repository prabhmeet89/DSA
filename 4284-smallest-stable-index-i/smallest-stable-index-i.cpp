class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        int suffixMin = nums[n - 1];

        // Find suffix minimums in-place is not allowed,
        // so use right[].
        vector<int> right(n);

        right[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            right[i] = min(nums[i], right[i + 1]);
        }

        int prefixMax = nums[0];

        for (int i = 0; i < n; ++i) {
            prefixMax = max(prefixMax, nums[i]);

            if (prefixMax - right[i] <= k)
                return i;
        }

        return -1;
    }
};