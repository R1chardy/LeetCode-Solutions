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
    int maxV = INT_MIN;
    int maxPathSum(TreeNode* root) {
        finder(root);
        return maxV;
    }
    
    void finder(TreeNode* root){
        if(root == nullptr){
            return;
        }
        finder(root->left);
        finder(root->right);
        int temp = helper(root);
        maxV = max(max(maxV, temp), root->val);
    }
    
    int helper(TreeNode* root){
        int L, R;
        if(root == nullptr){
            return 0;
        }
        else if(root->left == nullptr && root->right == nullptr){
            return root->val;
        }
        else if(root->left == nullptr){
            L = -1001;
            R = helper(root->right);
        }
        else if(root->right == nullptr){
            L = helper(root->left);
            R = -1001;
        }
        else{
            L = helper(root->left);
            R = helper(root->right);
        }
        
        maxV = max(maxV, L + R + root->val);
        
        return max(max(L + root->val, R + root->val), root->val);
    }
};