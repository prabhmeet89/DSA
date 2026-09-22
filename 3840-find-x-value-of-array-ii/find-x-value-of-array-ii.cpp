class Solution {
public:
    struct Node {
        int prod = 1;
        int cnt[5] = {};
    };

    int k;
    vector<Node> seg;

    Node merge(Node a, Node b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

        for (int i = 0; i < k; i++)
            res.cnt[i] = a.cnt[i];

        for (int i = 0; i < k; i++)
            res.cnt[(a.prod * i) % k] += b.cnt[i];

        return res;
    }

    void build(vector<int>& nums, int id, int l, int r) {
        if (l == r) {
            int x = nums[l] % k;
            seg[id].prod = x;
            seg[id].cnt[x] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(nums, id * 2, l, mid);
        build(nums, id * 2 + 1, mid + 1, r);

        seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
    }

    void update(int id, int l, int r, int pos, int val) {
        if (l == r) {
            val %= k;

            seg[id] = Node();
            seg[id].prod = val;
            seg[id].cnt[val] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(id * 2, l, mid, pos, val);
        else
            update(id * 2 + 1, mid + 1, r, pos, val);

        seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
    }

    Node query(int id, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[id];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(id * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(id * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(id * 2, l, mid, ql, qr);
        Node right = query(id * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        
        this->k = k;

        int n = nums.size();
        seg.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};