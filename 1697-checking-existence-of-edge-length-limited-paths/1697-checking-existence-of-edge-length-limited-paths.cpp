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
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> ret(queries.size());
        for(int i = 0; i < queries.size(); i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](auto& a, auto& b){
            return a[2] < b[2];
        });
        sort(edgeList.begin(), edgeList.end(), [](auto& a, auto& b){
            return a[2] < b[2];
        });
        UnionFind ds(n);
        
        int i = 0;
        for(auto& query : queries){
            while(i < edgeList.size() && edgeList[i][2] < query[2]){
                ds.unify(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            ret[query[3]] = ds.connected(query[0], query[1]);
        }
        return ret;
    }
};