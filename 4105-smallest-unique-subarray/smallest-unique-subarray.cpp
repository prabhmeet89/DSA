class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), temp(n);

        for(int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = nums[i];
        }

        for(int k = 1; k < n; k *= 2) {
            auto cmp = [&](int a, int b) {
                if(rank[a] != rank[b])
                    return rank[a] < rank[b];

                int x = (a + k < n) ? rank[a+k] : -1;
                int y = (b + k < n) ? rank[b+k] : -1;

                return x < y;
            };

            sort(sa.begin(), sa.end(), cmp);

            temp[sa[0]] = 0;

            for(int i = 1; i < n; i++) {
                temp[sa[i]] = temp[sa[i-1]] + cmp(sa[i-1], sa[i]);
            }

            rank = temp;
        }

        vector<int> pos(n), lcp(n, 0);

        for(int i = 0; i < n; i++)
            pos[sa[i]] = i;

        int h = 0;

        for(int i = 0; i < n; i++) {
            int j = pos[i];

            if(j == 0) continue;

            int prev = sa[j-1];

            while(i+h < n && prev+h < n && nums[i+h] == nums[prev+h])
                h++;

            lcp[j] = h;

            if(h > 0) h--;
        }

        int ans = n;

        for(int i = 0; i < n; i++) {
            int j = pos[i];

            int mx = lcp[j];

            if(j+1 < n)
                mx = max(mx, lcp[j+1]);

            if(mx < n-i)
                ans = min(ans, mx+1);
        }

        return ans;
    }
};