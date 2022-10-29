class UnionFind {
private:
    int num;
    int numComp;
    int* sz;
    int* root;
    
public:
    UnionFind(int n) {
        assert(n > 0);
        num = numComp = n;
        sz = new int[n];
        root = new int[n];
        for (int i = 0; i < n; i++) {
            sz[i] = 1;
            root[i] = i;
        }
    }
    
    int find(int x) {
        assert(x >= 0 && x < num);
        int head = x;
        while (head != root[head]) {
            head = root[head];
        }
        while (x != head) {
            root[x] = head;
            x = root[x];
        }
        return head;
    }
    
    bool unify(int p, int q){
        assert(p >= 0 && p < num && q >= 0 && q < num);
        int root1 = find(p);
        int root2 = find(q);
        if(root1 == root2){
            return false;
        }
        if(sz[root1] < sz[root2]){
            root[root1] = root2;
            sz[root2] += sz[root1];
        }
        else{
            root[root2] = root1;
            sz[root1] += sz[root2];
        }
        numComp--;
        return true;
    }
    
    bool connected(int p, int q){
        return find(p) == find(q);
    }
    
    int components(){
        return numComp;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind Alice(n+1);
        UnionFind Bob(n+1);
        int res = 0;
        for(auto x : edges){
            if(x[0] == 3){
                res += !(Alice.unify(x[1], x[2]) | Bob.unify(x[1], x[2]));
            }
        }
        for(auto x : edges){
            if(x[0] == 1){
                res += !Alice.unify(x[1], x[2]);
            }
            else if(x[0] == 2){
                res += !Bob.unify(x[1], x[2]);
            }
        }
        return (Alice.components() == 2 && Bob.components() == 2)? res : -1;
    }
};

