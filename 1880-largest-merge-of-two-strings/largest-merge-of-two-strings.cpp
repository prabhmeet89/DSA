class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans = "";

        while (!word1.empty() || !word2.empty()) {

            if (word1 > word2) {
                ans += word1[0];
                word1.erase(0, 1);
            }
            else {
                ans += word2[0];
                word2.erase(0, 1);
            }
        }

        return ans;
    }
};
