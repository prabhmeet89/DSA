class Solution {
public:
    vector<int> ans;
    vector<int> last = vector<int>(26, -1);
    vector<int> newParent;

    void dfs1(int node, vector<vector<int>>& adj, string& s) {

        int ch = s[node] - 'a';
        int old = last[ch];

        if(node != 0 && old != -1) {
            newParent[node] = old;
        }

        last[ch] = node;

        for(int child : adj[node]) {
            dfs1(child, adj, s);
        }

        last[ch] = old;
    }

    int dfs2(int node, vector<vector<int>>& adj) {

        int size = 1;

        for(int child : adj[node]) {
            size += dfs2(child, adj);
        }

        ans[node] = size;

        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        last.assign(26, -1);

        vector<vector<int>> adj(n);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        newParent = parent;

        dfs1(0, adj, s);

        vector<vector<int>> newAdj(n);

        for(int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        ans.resize(n);

        dfs2(0, newAdj);

        return ans;
    }
};