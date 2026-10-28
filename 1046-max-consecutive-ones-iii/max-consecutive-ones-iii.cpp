class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0, i = 0, j = 0;
        int maxlen = INT_MIN, len = INT_MIN;
        while(j<n){
            if(nums[j]==1) j++;
            else { // nums[j]==0
                if(flips<k){
                    flips++;
                    j++;
                }
                else{ // flips>k
                len = j-i;
                maxlen = max(maxlen,len);
                while(nums[i]==1) i++; // iska mtlb hai hai ki ab i first zero par agya hai or hum ab uske next idx par rkhna hai i ko
                i++;
                j++;
                }
            } 
        }
       len = j-i;
       maxlen = max(maxlen,len);
       return maxlen; 
    }
};