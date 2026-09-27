class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        if (n == 2){
            if(target==nums[0]) return 0;
            else if (target==nums[1]) return 1;
            else return -1;
        }
            

        int pivot = -1;

        // Find pivot
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                pivot = mid;
                break;
            }

            if (mid < n - 1 && nums[mid] > nums[mid + 1]) {
                pivot = mid + 1;
                break;
            }

            if (nums[mid] >= nums[0])
                low = mid + 1;
            else
                high = mid - 1;
        }

        // Array already sorted
        if (pivot == -1) {
            low = 0;
            high = n - 1;
        }

        // Left sorted part
        else if (target >= nums[0] && target <= nums[pivot - 1]) {
            low = 0;
            high = pivot - 1;
        }

        // Right sorted part
        else {
            low = pivot;
            high = n - 1;
        }

        // Binary Search
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1;
    }
};