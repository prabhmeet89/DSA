class Solution {
public:
    void reverse(vector<int>& nums, int si, int ei){
        while(si<=ei){
            int temp = nums[si];
            nums[si] = nums[ei];
            nums[ei] = temp;
            si++;
            ei--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) k = k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);   
    }
};