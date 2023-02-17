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
    
    int sum = 0;
    int temp = 0;
    
    int sumNumbers(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        solve(root);
        return sum;
    }
    
    void solve(TreeNode* root){
        
        temp *= 10;
        temp += root->val;
        
        if(root->left == nullptr && root->right == nullptr){
            sum += temp;
            temp /= 10;
            return;
        }
        
        if(root->left != nullptr){
            solve(root->left);
        }
        if(root->right != nullptr){
            solve(root->right);
        }
        
        temp /= 10;
    }
};