
class Solution {
    using ll = long long;

    struct BIT {
        int n;
        vector<ll> bit;

        BIT(int n) : n(n), bit(n + 1, 0) {}

        void update(int i, ll val) {
            for (; i <= n; i += i & -i)
                bit[i] += val;
        }

        ll query(int i) {
            ll sum = 0;
            for (; i > 0; i -= i & -i)
                sum += bit[i];
            return sum;
        }

        // Find smallest index with prefix sum >= k
        int kth(ll k) {
            int idx = 0;

            for (int pw = 1 << (31 - __builtin_clz(n));
                 pw; pw >>= 1) {
                int next = idx + pw;

                if (next <= n && bit[next] < k) {
                    idx = next;
                    k -= bit[next];
                }
            }

            return idx + 1;
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        if (1LL * x * k > n) return -1;

        // Coordinate compression
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());

        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();

        vector<int> id(n);

        for (int i = 0; i < n; i++) {
            id[i] = lower_bound(vals.begin(), vals.end(),
                                nums[i]) - vals.begin() + 1;
        }

        BIT cnt(m), sum(m);

        ll totalSum = 0;

        // Add element
        auto add = [&](int i) {
            cnt.update(id[i], 1);
            sum.update(id[i], nums[i]);
            totalSum += nums[i];
        };

        // Remove element
        auto remove = [&](int i) {
            cnt.update(id[i], -1);
            sum.update(id[i], -nums[i]);
            totalSum -= nums[i];
        };

        // Cost of current window
        auto getCost = [&]() -> ll {
            int mid = cnt.kth((x + 1) / 2);

            ll median = vals[mid - 1];

            ll leftCount = cnt.query(mid);
            ll leftSum = sum.query(mid);

            ll rightCount = x - leftCount;
            ll rightSum = totalSum - leftSum;

            return median * leftCount - leftSum
                 + rightSum - median * rightCount;
        };

        // Calculate all window costs
        int w = n - x + 1;

        vector<ll> cost(w);

        for (int i = 0; i < x; i++)
            add(i);

        cost[0] = getCost();

        for (int i = 1; i < w; i++) {
            remove(i - 1);
            add(i + x - 1);

            cost[i] = getCost();
        }

        // DP with O(n) space
        const ll INF = LLONG_MAX / 4;

        vector<ll> prev(n + 1, 0);
        vector<ll> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = n - 1; i >= 0; i--) {

                // Skip current index
                curr[i] = curr[i + 1];

                // Take window starting at i
                if (i + x <= n) {
                    curr[i] = min(
                        curr[i],
                        cost[i] + prev[i + x]
                    );
                }
            }

            swap(prev, curr);
        }

        return prev[0];
    }
};
