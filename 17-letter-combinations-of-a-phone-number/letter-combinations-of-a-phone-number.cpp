class Solution {
public:
    vector<string> ans;
    string path;
    string mp[10] = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string& digits, int i) {
        if (i == digits.size()) {
            ans.push_back(path);
            return;
        }

        for (char c : mp[digits[i] - '0']) {
            path.push_back(c);
            solve(digits, i + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        solve(digits, 0);
        return ans;
    }
};