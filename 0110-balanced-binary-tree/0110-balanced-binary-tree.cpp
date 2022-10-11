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
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
    
    pair<bool, int> dfs(TreeNode* root){
        if(root == nullptr || root->left == nullptr && root->right == nullptr){
            return {true, 1};
        }
        
        bool valid = true;
        int left = 0;
        int right = 0;
        pair<bool, int> temp;
        if(root->left != nullptr){
            temp = dfs(root->left);
            left = temp.second;
            valid = valid && temp.first;
        }
        if(root->right != nullptr){
            temp = dfs(root->right);
            right = temp.second;
            valid = valid && temp.first;
        }
        if(abs(right - left) > 1){
            valid = false;
        }
        return {valid, 1 + max(left, right)};
    }
};