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
    int maxL = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = solve(root);
        return max(maxL, ans)-1;
    }
    
    int solve(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        maxL = max(maxL, 1 + right + left);
        return 1 + max(right, left);
    }
};