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
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 1));
        UnionFind ds(row*col+2);
        for(int i = cells.size()-1; i >= 0; i--){
            grid[cells[i][0]-1][cells[i][1]-1] = 0;
            unifyFour(ds, grid, cells[i][0]-1, cells[i][1]-1);
            if(ds.connected(0, row*col+1)){
                return i;
            }
        }
        return 0;
    }
    
    void unifyFour(UnionFind& ds, vector<vector<int>>& grid, int i, int j){
        if(i > 0 && grid[i-1][j] == 0){
            ds.unify((i-1)*grid[0].size() + j + 1, i*grid[0].size() + j + 1);
        }
        if(i < grid.size()-1 && grid[i+1][j] == 0){
            ds.unify((i+1)*grid[0].size() + j + 1, i*grid[0].size() + j + 1);
        }
        if(j > 0 && grid[i][j-1] == 0){
            ds.unify(i*grid[0].size() + j, i*grid[0].size() + j + 1);
        }
        if(j < grid[0].size()-1 && grid[i][j+1] == 0){
            ds.unify(i*grid[0].size() + j + 1, i*grid[0].size() + j + 2);
        }
        if(i == 0){
            ds.unify(j + 1, 0);
        }
        if(i == grid.size()-1){
            ds.unify(i*grid[0].size() + j + 1, grid.size()*grid[0].size()+1);
        }
    }
};