class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // if(root == NULL) return NULL;

        // TreeNode* left = invertTree(root->left);
        // TreeNode* right = invertTree(root->right); 

        // root->left = right;
        // root->right = left;

        // return root;   

        if(root == NULL ) return NULL;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            swap(node->left,node->right);

            if(node->right != NULL) q.push(node->right);
            if(node->left != NULL) q.push(node->left);
        }

        return root;
    }
};