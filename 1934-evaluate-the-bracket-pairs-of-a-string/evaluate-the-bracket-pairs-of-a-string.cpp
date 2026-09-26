class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (auto &v : knowledge)
            mp[v[0]] = v[1];

        string ans;
        ans.reserve(s.size());

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(') {
                ans += s[i];
                continue;
            }

            int j = i + 1;
            while (s[j] != ')') j++;

            string key = s.substr(i + 1, j - i - 1);

            auto it = mp.find(key);
            ans += (it == mp.end() ? "?" : it->second);

            i = j;
        }

        return ans;
    }
};