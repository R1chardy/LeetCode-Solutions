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
    unordered_map<TreeNode*,int> dp;
    int rob(TreeNode* root) {
        if(dp[root]){
            return dp[root];
        }
        else if(root == nullptr){
            return 0;
        }
        else{
            if(root->left == nullptr && root->right == nullptr){
                return dp[root] = root->val;
            }
            else if(root->left == nullptr && root->right != nullptr){
                return dp[root] = max(root->val + rob(root->right->left)+ rob(root->right->right), rob(root->right));
            }
            else if(root->left != nullptr && root->right == nullptr){
                return dp[root] = max(root->val + rob(root->left->left)+ rob(root->left->right), rob(root->left));
            }
            else{
                return dp[root] = max(root->val + rob(root->left->left)+ rob(root->left->right) + rob(root->right->left)+ rob(root->right->right), rob(root->left) + rob(root->right));
            }
        }
    }
};