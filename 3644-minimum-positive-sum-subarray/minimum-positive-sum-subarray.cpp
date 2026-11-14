
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<long long> prefix(n+1, 0);

        for(int i = 0; i<n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }

        long long ans = LLONG_MAX;

        for(int i = 0; i<n; i++){
            for(int j = i+l; j<=min(n, i+r); j++){
                long long sum = prefix[j] - prefix[i];

                if(sum > 0){
                    ans = min(ans, sum);
                }
            }
        }

        if(ans == LLONG_MAX) return -1;
        return (int)ans;
    }
};
