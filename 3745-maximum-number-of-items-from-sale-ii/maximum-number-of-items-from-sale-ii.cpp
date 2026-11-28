class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mx = 0, minPrice = INT_MAX;

        for (auto& item : items) {
            mx = max(mx, item[0]);
            minPrice = min(minPrice, item[1]);
        }

        // Count frequency of each factor
        vector<int> freq(mx + 1, 0);

        for (auto& item : items) {
            freq[item[0]]++;
        }

        // Calculate how many item types each factor can unlock
        vector<int> total(mx + 1, 0);

        for (int f = 1; f <= mx; f++) {
            for (int j = f; j <= mx; j += f) {
                total[f] += freq[j];
            }
        }

        // Group bonus copies by price
        map<int, long long> bonusByPrice;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            int gain = total[factor] - 1; // exclude same item type

            if (gain > 0 && price < 2LL * minPrice) {
                bonusByPrice[price] += gain;
            }
        }

        long long rem = budget;
        long long ans = 0;

        // Buy value-2 copies in increasing order of price
        for (auto& [price, count] : bonusByPrice) {
            if (rem < price) break;

            long long take = min(count, rem / price);

            ans += take * 2;
            rem -= take * price;
        }

        // Spend remaining budget on cheapest item (value-1 copies)
        ans += rem / minPrice;

        return (int)ans;
    }
};