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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        vector<int> temp;
        int maxInt = 1;
        int Inting = 0;
        int Inter = 0;
        if(root != nullptr){
            q.push(root);
        }
        while(!q.empty()){
            temp.push_back(q.front()->val);
            if(q.front()->left != nullptr){
                q.push(q.front()->left);
                Inter++;
            }
            if(q.front()->right != nullptr){
                q.push(q.front()->right);
                Inter++;
            }
            q.pop();
            Inting++;
            if(Inting == maxInt){
                maxInt = Inter;
                Inter = 0;
                Inting = 0;
                ret.push_back(temp);
                temp.clear();
            }
        }
        if(temp.size() > 0){
            ret.push_back(temp);
        }
        return ret;
    }
};