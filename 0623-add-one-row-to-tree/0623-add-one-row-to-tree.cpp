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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == nullptr){
            return root;
        }
        else if(depth == 1){
            TreeNode* newRoot = new TreeNode(val, root, nullptr);
            return newRoot;
        }
        else if(depth == 2){
            TreeNode* leftC = new TreeNode(val, root->left, nullptr);
            TreeNode* rightC = new TreeNode(val, nullptr, root->right);
            root->left = leftC;
            root->right = rightC;
            return root;
        }
        else{
            root->left = addOneRow(root->left, val, depth - 1);
            root->right = addOneRow(root->right, val, depth - 1);
            return root;
        }
    }
};