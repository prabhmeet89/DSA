
class Solution {
public:
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> ans;

        if (start > end) {
            ans.push_back(nullptr);
            return ans;
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = generate(start, i - 1);
            vector<TreeNode*> rightTrees = generate(i + 1, end);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }
};
