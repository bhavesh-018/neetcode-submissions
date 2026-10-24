/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode* > level;
        level.push(root);

        while(!level.empty()){
            int n = level.size();

            vector<int> partialRes;
            for(int i=0; i<n; i++){
                TreeNode* node = level.front();
                partialRes.emplace_back(node->val);
                if(node->left) level.push(node->left);
                if(node->right) level.push(node->right);
                level.pop();
            }
            res.emplace_back(partialRes);
        }
        return res;
    }
};
