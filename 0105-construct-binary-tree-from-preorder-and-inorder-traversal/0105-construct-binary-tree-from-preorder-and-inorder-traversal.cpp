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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preI = 0;
        return solve(preorder, inorder, preI, 0, inorder.size()-1);
    }
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preI, int beg, int end){
        if(beg > end){
            return nullptr;
        }
        int mid = find(inorder.begin(), inorder.end(), preorder[preI]) - inorder.begin();
        TreeNode* ret = new TreeNode(preorder[preI]);
        preI++;
        ret->left = solve(preorder, inorder, preI, beg, mid-1);
        ret->right = solve(preorder, inorder, preI, mid+1, end);
        return ret;
    }
};