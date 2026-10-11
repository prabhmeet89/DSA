
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;

        for (char ch = 'a'; ch <= 'z'; ch++) {
            bool lower = false;
            bool upper = false;

            for (char c : word) {
                if (c == ch) {
                    lower = true;
                }
                if (c == ch - 32) {
                    upper = true;
                }
            }

            if (lower && upper) {
                count++;
            }
        }

        return count;
    }
};
