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
        return valid(root->left, LONG_MIN, root->val) && valid(root->right, root->val, LONG_MAX);
    }
    bool valid(TreeNode* root, long minV, long maxV) {
        if(root == nullptr){
            return true;
        }
        else if(root->val <= minV || root->val >= maxV){
            return false;
        }
        else{
            bool lValid = valid(root->left, minV, root->val);
            bool rValid = valid(root->right, root->val, maxV);
            return lValid && rValid;
        }
    }
};