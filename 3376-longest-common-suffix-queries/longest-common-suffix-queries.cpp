
class Solution {
public:
    struct Node {
        int child[26];
        int best;
        Node() {
            fill(child, child + 26, -1);
            best = -1;
        }
    };

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        int best = 0;

        for (int i = 1; i < n; i++) {
            if (wordsContainer[i].size() <
                wordsContainer[best].size()) {
                best = i;
            }
        }

        vector<Node> trie(1);

        auto update = [&](int node, int idx) {
            if (trie[node].best == -1 ||
                wordsContainer[idx].size() <
                wordsContainer[trie[node].best].size()) {
                trie[node].best = idx;
            }
        };

        for (int i = 0; i < n; i++) {
            int node = 0;
            update(node, i);

            for (int j = (int)wordsContainer[i].size() - 1;
                 j >= 0; j--) {
                int c = wordsContainer[i][j] - 'a';

                if (trie[node].child[c] == -1) {
                    trie[node].child[c] = trie.size();
                    trie.emplace_back();
                }

                node = trie[node].child[c];
                update(node, i);
            }
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());

        for (const string& q : wordsQuery) {
            int node = 0;

            for (int j = (int)q.size() - 1; j >= 0; j--) {
                int c = q[j] - 'a';

                if (trie[node].child[c] == -1)
                    break;

                node = trie[node].child[c];
            }

            ans.push_back(trie[node].best);
        }

        return ans;
    }
};
