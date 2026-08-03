class Solution {
public:
    void sortColors(vector<int>& nums) { 
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;
        while(mid<=high) {
            // 1 condition
            if(nums[mid]==2) {
                // swap (mid , high)
                int temp = nums[mid];
                nums[mid] = nums[high];
                nums[high] = temp;
                high--;
            }

            else if(nums[mid]==0) {
                // swap (low , mid)
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                low++;
                mid++;
            }

            else if(nums[mid]==1) {
                mid++;
            }
        }
      return;
    }  
};
    