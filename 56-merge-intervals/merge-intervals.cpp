class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++) {

            // If answer is empty OR no overlap
            if (ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            }
            else {
                // Overlapping intervals
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};