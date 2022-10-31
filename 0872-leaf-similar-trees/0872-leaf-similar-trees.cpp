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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1;
        getLeaf(root1, r1);
        vector<int> r2;
        getLeaf(root2, r2);
        return r1 == r2;
    }
    
    void getLeaf(TreeNode* root, vector<int>& t1){
        if(root == nullptr){
            return;
        }
        else if(root->left == nullptr && root->right == nullptr){
            t1.push_back(root->val);
        }
        getLeaf(root->left, t1);
        getLeaf(root->right, t1);
    }
};