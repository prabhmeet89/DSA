
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](const auto& a, const auto& b) {
                 return a[1] < b[1];
             });

        vector<pair<int,int>> q;

        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(queries.size());

        int l = 0, r = 0;
        int active = 0;

        for(auto [t, idx] : q) {

            while(r < logs.size() && logs[r][1] <= t) {
                int id = logs[r][0];

                if(freq[id] == 0) active++;

                freq[id]++;
                r++;
            }

            while(l < r && logs[l][1] < t - x) {
                int id = logs[l][0];

                freq[id]--;

                if(freq[id] == 0) active--;

                l++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};
