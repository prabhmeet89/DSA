class Solution {
public:
    long long countCommas(int n) {
        long long ans = 0;

        if (n >= 1000) {
            ans += min(n, 999999) - 1000 + 1;
        }

        if (n >= 1000000) {
            ans += 2LL * (min(n, 999999999) - 1000000 + 1);
        }

        if (n >= 1000000000) {
            ans += 3LL * (1LL * n - 1000000000 + 1);
        }

        return ans;
    }
};