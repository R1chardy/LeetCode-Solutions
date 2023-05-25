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
    //0: not covered, 1: covered, 2: camera
    int nums = 0;
    int minCameraCover(TreeNode* root) {
        if(solve(root) == 0){
            nums++;
        }
        return nums;
    }
    
    int solve(TreeNode* root){
        if(root == nullptr){
            return 1;
        }
        int l = solve(root->left);
        int r = solve(root->right);
        if(l == 0 || r == 0){
            nums++;
            return 2;
        }
        else if(l == 1 && r == 1){
            return 0;
        }
        else{
            return 1;
        }
    }
};