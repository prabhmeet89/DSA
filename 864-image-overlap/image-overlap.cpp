class Solution {
public:
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size(), ans = 0;
        vector<pair<int,int>> x, y;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) {
                if(a[i][j]) x.push_back({i,j});
                if(b[i][j]) y.push_back({i,j});
            }

        map<pair<int,int>,int> mp;

        for(auto p:x)
            for(auto q:y)
                ans = max(ans, ++mp[{q.first-p.first, q.second-p.second}]);

        return ans;
    }
};