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
    vector<vector<int>> sol = {};
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return sol;
        }
        res.push_back(root->val);
        helper(root, targetSum, root->val);
        return sol;
    }
    
    vector<int> res = {};
    bool helper(TreeNode* root, int targetSum, int currSum){
        if(currSum != targetSum && root->left == nullptr && root->right == nullptr){
            return false;
        }
        else if(currSum == targetSum && root->left == nullptr && root->right == nullptr){
            sol.push_back(res);
            return true;
        }
        else{
            if(root->left != nullptr){
                res.push_back(root->left->val);
                helper(root->left, targetSum, currSum + root->left->val);
                res.pop_back();
            }
            if(root->right != nullptr){
                res.push_back(root->right->val);
                helper(root->right, targetSum, currSum + root->right->val);
                res.pop_back();
            }
        }
        return false;
    }
};