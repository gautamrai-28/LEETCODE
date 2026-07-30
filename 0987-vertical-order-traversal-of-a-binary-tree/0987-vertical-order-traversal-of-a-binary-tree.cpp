class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       vector<vector<int>>ans;

       if(root == NULL) 
          return ans; 

       queue<pair<TreeNode*, pair<int,int>>>q;
       q.push({root, {0,0}});

       map<int,map<int, multiset<int>>>mpp;

       while(!q.empty()) {
        auto p = q.front();

        TreeNode* node = p.first;
        int vertical = p.second.first;
        int level = p.second.second;

        q.pop();

        if(node->left) q.push({node->left, {vertical - 1, level+1 }});
        if(node->right) q.push({node->right, {vertical + 1, level+1 }});

        mpp[vertical][level].insert(node->val);
       }

       for (auto &col : mpp) {
            vector<int> temp;

            for (auto &row : col.second) {
                temp.insert(temp.end(),
                            row.second.begin(),
                            row.second.end());
            }

            ans.push_back(temp);
        }

        return ans;
    }
};