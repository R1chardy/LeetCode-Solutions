struct Node {
    Node *left, *right;
    int val, lazy;
    Node() : left(nullptr), right(nullptr), val(0), lazy(0) {}
    Node(int v) : left(nullptr), right(nullptr), val(v), lazy(0) {}
};
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        this->l = buildings[0][0];
        this->r = rightMostHelper(buildings);
        for (auto& building : buildings) {
            update(root, l, r, building[0], building[1] - 1, building[2]);
        }
        query(root, l, r);
        return ret;
    }
private:
    void update(Node* node, int l, int r, int start, int end, int height) {
        if (start <= l && r <= end) {
            node->lazy = max(node->lazy, height);
            node->val = max(node->val, height);
            return;            
        }
        pushDown(node);
        int mid = l + (r - l) / 2;
        if (start <= mid) {
            update(node->left, l, mid, start, end, height);
        }
        if (mid < end) {
            update(node->right, mid + 1, r, start, end, height);
        }
    }
    void query(Node* node, int l, int r) {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) {
            if (ret.empty() || node->val != ret.back()[1])
                ret.push_back({l, node->val});
            return;
        }
        int mid = l + (r - l) / 2;
        pushDown(node);
        query(node->left, l, mid);
        query(node->right, mid + 1, r);
    }
    void pushDown(Node* node) {
        if (not node->left) node->left = new Node(node->val);
        if (not node->right) node->right = new Node(node->val);
        if (node->lazy == 0) return;
        node->left->lazy = max(node->lazy, node->left->lazy);
        node->left->val = max(node->lazy, node->left->val);
        node->right->lazy = max(node->lazy, node->right->lazy);
        node->right->val = max(node->lazy, node->right->val);
        node->lazy = 0;
        return;
    }
    int rightMostHelper(vector<vector<int>>& buildings) {
        int r = 0;
        for (auto& building : buildings) r = max(r, building[1]);
        return r;
    }
    int l, r;
    Node* root = new Node();
    vector<vector<int>> ret;
};