class Solution {
public:
    int height(TreeNode* root) {
        if(root == NULL) return 0;

        int leftHt = height(root->left);
        if(leftHt == -1) return -1;

        int rightHt = height(root->right);
        if(rightHt == -1) return -1;

        if(abs(leftHt - rightHt)>1) return -1;

        return 1 + max(rightHt,leftHt);
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};