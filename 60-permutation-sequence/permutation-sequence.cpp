class Solution {
public:
    string helper(string str, int k, string ans) {
        int n = str.size();

        if(n == 1) {
            return ans + str[0];
        }

        int fact = 1;
        for(int i = 2; i <= n - 1; i++) {
            fact *= i;
        }

        int idx = k / fact;

        char ch = str[idx];

        string left = str.substr(0, idx);
        string right = str.substr(idx + 1);

        int q = k % fact;

        return helper(left + right, q, ans + ch);
    }

    string getPermutation(int n, int k) {
        string str = "";

        for(int i = 1; i <= n; i++) {
            str += to_string(i);
        }

        k--;

        return helper(str, k, "");
    }
};