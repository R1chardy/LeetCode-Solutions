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
        if(root == nullptr){
            return true;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if(left >= 5001 || right >= 5001 || abs(left - right) > 1){
            return false;
        }
        return true;
    }
    
    int getHeight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        
        if(abs(left - right) > 1){
            return 5001;
        }
        return 1 + max(left, right);
    }
};