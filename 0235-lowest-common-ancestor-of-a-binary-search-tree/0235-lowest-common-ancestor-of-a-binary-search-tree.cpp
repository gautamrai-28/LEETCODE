class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
          return root;
        
        if(root->val>p->val && root->val>q->val) 
          return lowestCommonAncestor(root->left, p, q);//left subtree call
        else if(root->val<p->val && root->val<q->val) 
          return lowestCommonAncestor(root->right, p, q);//right subtree call
        else 
          return root;//LCA found
    }
};