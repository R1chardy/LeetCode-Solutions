/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> corr;
    unordered_set<Node*> visited;
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return node;
        }
        return traverse(node);
    }
    
    Node* traverse(Node* node){
        visited.emplace(node);
        Node* dCopy = new Node(node->val);
        corr[node] = dCopy;
        for(auto x : node->neighbors){
            if(visited.count(x) == 0){
                visited.emplace(x);
                dCopy->neighbors.push_back(traverse(x));
            }
            else{
                dCopy->neighbors.push_back(corr[x]);
            }
        }
        return dCopy;
    }
};