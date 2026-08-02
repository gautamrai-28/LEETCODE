class Solution {
public:
    int order = 0;
    int ans = -1;
    void inOrder(TreeNode* root, int k) {
        if(root) {
            inOrder(root->left,k);
            order++;
            if(order == k) ans = root->val; 
            inOrder(root->right,k);
        }
    } 
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root,k);
        return ans;
    }
};