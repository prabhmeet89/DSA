
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int bits[32] = {0};
        int left = 0;
        int ans = INT_MAX;
        int currOR = 0;

        for (int right = 0; right < n; right++) {
            for (int b = 0; b < 32; b++) {
                if (nums[right] & (1LL << b)) {
                    bits[b]++;
                }
            }

            currOR |= nums[right];

            while (left <= right && currOR >= k) {
                ans = min(ans, right - left + 1);

                for (int b = 0; b < 32; b++) {
                    if (nums[left] & (1LL << b)) {
                        bits[b]--;
                    }
                }

                currOR = 0;
                for (int b = 0; b < 32; b++) {
                    if (bits[b] > 0) {
                        currOR |= (1LL << b);
                    }
                }

                left++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
