class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);

        int currRow = 0;
        bool goingDown = false;

        for (char ch : s) {
            rows[currRow] += ch;

            // Change direction at top and bottom
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }

            if (goingDown) {
                currRow++;
            } else {
                currRow--;
            }
        }

        string ans = "";

        for (string row : rows) {
            ans += row;
        }

        return ans;
    }
};