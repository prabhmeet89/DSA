class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2,-1);

        int low = 0;
        int high = n - 1;

        // First occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans[0] = mid;
                high = mid - 1;   // left side search
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        low = 0;
        high = n - 1;

        // Last occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans[1] = mid;
                low = mid + 1;    // right side search
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};