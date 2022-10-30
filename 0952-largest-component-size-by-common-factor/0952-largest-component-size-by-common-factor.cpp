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
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        UnionFind ds(*max_element(nums.begin(), nums.end())+1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 2; j <= sqrt(nums[i]); j++){
                if(nums[i]%j == 0){
                    ds.unify(nums[i], j);
                    ds.unify(nums[i], nums[i]/j);
                }
            }
        }
        int large = 0;
        map<int, int> counts;
        for(int i = 0; i < nums.size(); i++){
            counts[ds.find(nums[i])]++;
            large = max(large, counts[ds.find(nums[i])]);
            
        }
        return large;
    }
};