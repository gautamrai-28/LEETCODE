class Solution {
public:
    int ans = INT_MIN;

    int maxGain(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = max(0, maxGain(root->left));
        int right = max(0, maxGain(root->right));

        ans = max(ans, left + right + root->val);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return ans;
    }
};