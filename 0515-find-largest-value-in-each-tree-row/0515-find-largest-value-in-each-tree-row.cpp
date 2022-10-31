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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        int len, maxV;
        while(!q.empty()){
            maxV = INT_MIN;
            len = q.size();
            while(len--){
                maxV = max(maxV, q.front()->val);
                if(q.front()->left != nullptr){
                    q.push(q.front()->left);
                }
                if(q.front()->right != nullptr){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            res.push_back(maxV);
        }
        return res;
    }
};