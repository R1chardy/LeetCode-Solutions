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
    vector<int> t1;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        getLeaf(root1);
        vector<int> r1(t1);
        t1.clear();
        getLeaf(root2);
        vector<int> r2(t1);
        t1.clear();
        return r1 == r2;
    }
    
    void getLeaf(TreeNode* root){
        if(root == nullptr){
            return;
        }
        getLeaf(root->left);
        getLeaf(root->right);
        if(root->left == nullptr && root->right == nullptr){
            t1.push_back(root->val);
        }
    }
};