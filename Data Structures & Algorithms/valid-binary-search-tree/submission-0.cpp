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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }

    bool dfs(TreeNode* root, long long minVal, long long maxVal){
        if(!root) return true;
        if(!(minVal < root->val && root->val < maxVal))
            return false;
        return dfs(root->left, minVal, root->val) && dfs(root->right, root->val, maxVal);
    }
};
