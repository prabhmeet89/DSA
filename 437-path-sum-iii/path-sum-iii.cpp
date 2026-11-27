class Solution {
public:
    int count = 0;

    void helper(TreeNode* root, long long sum) {
        if (root == NULL) return;

        if (root->val == sum) {
            count++;
        }

        helper(root->left, sum - root->val);
        helper(root->right, sum - root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;

        helper(root, targetSum);

        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return count;
    }
};