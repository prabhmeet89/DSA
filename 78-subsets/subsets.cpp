class Solution {
public:
    void helper(vector<int>& nums,vector<int> ans, vector<vector<int>>& FinalAns,int idx){
        if(idx==nums.size()){
            FinalAns.push_back(ans);
            return;
        }
        helper(nums,ans,FinalAns,idx+1);
        ans.push_back(nums[idx]);
        helper(nums,ans,FinalAns,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> ans;
    vector<vector<int>> FinalAns;
    helper(nums,ans,FinalAns,0);
    return FinalAns;    
    }
};