class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int m = target;
        for(int i = 0; i<n-1 ; i++) {
            for(int j = i+1; j<n; j++){
                if (nums[i]+nums[j]==m) return {i,j};
            }
        }
        return {};
    }    
};