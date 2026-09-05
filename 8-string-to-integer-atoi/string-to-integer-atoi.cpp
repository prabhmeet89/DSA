class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        int sign = 1;
        int ans = 0;

        // Skip spaces
        while (i < n && s[i] == ' ')
            i++;

        // Sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        // Digits
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            // Overflow check BEFORE multiplication
            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return sign * ans;
    }
};