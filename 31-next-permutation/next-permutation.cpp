class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pidx = -1;

        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                pidx = i;
                break;
            }
        }

        if(pidx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Next greater element find karo
        int idx = n-1;
        while(nums[idx] <= nums[pidx]){
            idx--;
        }

        // Pivot aur next greater element swap karo
        swap(nums[pidx], nums[idx]);

        // Ab suffix reverse karo
        reverse(nums.begin()+pidx+1, nums.end());
    }
};