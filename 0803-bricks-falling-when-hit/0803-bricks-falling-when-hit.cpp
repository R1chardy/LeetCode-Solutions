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
    
    int componentSize(int p){
        assert(p >= 0 && p < num);
        return sz[find(p)];
    }   
    
    bool connected(int p, int q){
        return find(p) == find(q);
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        UnionFind ds(grid.size() * grid[0].size() + 1);
        for(auto x : hits){
            if(grid[x[0]][x[1]] == 1){
                grid[x[0]][x[1]] = 2;
            }
        }
        for(int i = 0; i < grid[0].size(); i++){
            if(grid[0][i] == 1){
                ds.unify(i+1, 0);
            }
        }
        // for(int i = 0; i < grid[0].size()-1; i++){
        //     if(grid[0][i] == 1 && grid[0][i+1] == 1){
        //         ds.unify(i+1, i+2);
        //     }
        // }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    unifyFour(ds, grid, i, j);
                }
            }
        }
        int prev, now;
        vector<int> res(hits.size(), 0);
        for(int i = hits.size()-1; i >= 0; i--){
            if(grid[hits[i][0]][hits[i][1]] != 2){
                continue;
            }
            prev = ds.componentSize(0);
            grid[hits[i][0]][hits[i][1]] = 1;
            unifyFour(ds, grid, hits[i][0], hits[i][1]);
            now = ds.componentSize(0);
            if(now != prev){
                res[i] = now - prev - 1;
            }
        }
        return res;
        
    }
    
    void unifyFour(UnionFind& ds, vector<vector<int>>& grid, int i, int j){
        if(i > 0 && grid[i-1][j] == 1){
            ds.unify((i-1)*grid[0].size() + j + 1, i*grid[0].size() + j + 1);
        }
        if(i < grid.size()-1 && grid[i+1][j] == 1){
            ds.unify((i+1)*grid[0].size() + j + 1, i*grid[0].size() + j + 1);
        }
        if(j > 0 && grid[i][j-1] == 1){
            ds.unify(i*grid[0].size() + j, i*grid[0].size() + j + 1);
        }
        if(j < grid[0].size()-1 && grid[i][j+1] == 1){
            ds.unify(i*grid[0].size() + j + 1, i*grid[0].size() + j + 2);
        }
        if(i == 0){
            ds.unify(j + 1, 0);
        }
    }
};