class Solution {
public:
    int reverse(int x) {
        int r = 0;

        while (x != 0) {
            int lsd = x % 10;

            if (r > INT_MAX / 10 || (r == INT_MAX / 10 && lsd > 7))
                return 0;
            if (r < INT_MIN / 10 || (r == INT_MIN / 10 && lsd < -8))
                return 0;

            r = r * 10;
            r += lsd;
            x = x / 10;
        }

        return r;
    }
};