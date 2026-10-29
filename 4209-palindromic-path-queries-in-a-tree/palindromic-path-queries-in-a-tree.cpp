
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1), depth(n, 0);
        vector<int> sz(n, 1), heavy(n, -1);
        vector<int> order;
        order.reserve(n);

        // Build parent and depth iteratively
        vector<int> st = {0};
        parent[0] = 0;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
            order.push_back(u);

            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back(v);
            }
        }

        // Subtree sizes and heavy child
        for (int i = n - 1; i >= 0; --i) {
            int u = order[i];
            int best = 0;

            for (int v : adj[u]) {
                if (parent[v] != u) continue;

                sz[u] += sz[v];
                if (sz[v] > best) {
                    best = sz[v];
                    heavy[u] = v;
                }
            }
        }

        vector<int> head(n), pos(n);
        int timer = 0;

        // Assign HLD chains
        vector<pair<int, int>> chains = {{0, 0}};

        while (!chains.empty()) {
            auto [start, h] = chains.back();
            chains.pop_back();

            for (int u = start; u != -1; u = heavy[u]) {
                head[u] = h;
                pos[u] = timer++;

                for (int v : adj[u]) {
                    if (parent[v] == u && v != heavy[u]) {
                        chains.push_back({v, v});
                    }
                }
            }
        }

        // Segment tree storing XOR character masks
        vector<int> seg(2 * n, 0);

        for (int u = 0; u < n; ++u) {
            seg[n + pos[u]] = 1 << (s[u] - 'a');
        }

        for (int i = n - 1; i > 0; --i) {
            seg[i] = seg[i * 2] ^ seg[i * 2 + 1];
        }

        auto update = [&](int p, int val) {
            p += n;
            seg[p] = val;

            for (p >>= 1; p > 0; p >>= 1) {
                seg[p] = seg[p * 2] ^ seg[p * 2 + 1];
            }
        };

        auto rangeQuery = [&](int l, int r) {
            int res = 0;
            for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res ^= seg[l++];
                if (r & 1) res ^= seg[--r];
            }
            return res;
        };

        vector<bool> ans;

        for (const string &q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;
                s[u] = c;
                update(pos[u], 1 << (c - 'a'));
            } else {
                ss >> v;
                int mask = 0;

                while (head[u] != head[v]) {
                    if (depth[head[u]] < depth[head[v]]) {
                        swap(u, v);
                    }

                    mask ^= rangeQuery(pos[head[u]], pos[u]);
                    u = parent[head[u]];
                }

                if (depth[u] > depth[v]) swap(u, v);

                mask ^= rangeQuery(pos[u], pos[v]);

                // At most one character may have odd frequency
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
