class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // pivot index
       //1. // yeh index isiliye nikal rahe ki iske baad cahneg ara to hume pata chle 
        int idx = -1;
        for(int i = n-2; i>=0; i--) {
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }

       //2. // check if array is in already in its highest numbr
        if(idx==-1) {
          reverse(nums.begin(),nums.end());
          return;
        }

        // reverse elements krna hai pivot index ke baad wale
        reverse(nums.begin()+idx+1 , nums.end());

        // ab hume swap krna hai uss element ko jo pivot hai just usse ek bade element ke baad wale se 

        int j = -1;
        for(int i = idx+1; i<n; i++){
            if(nums[i]>nums[idx]){
                j=i;
                break;
            }
        }

        // ab hume pivot wla element mil gya or usse ek just bada bhi ab hume usse swap kr denge
        int temp = nums[idx];
        nums[idx] = nums[j];
        nums[j] = temp;
        return;

     

    }
};