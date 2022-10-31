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
    
    int components() const{
        return numComp;
    }
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        UnionFind ds(words.size());
        vector<int> masks(words.size(), 0);
        unordered_map<int, int> hash;
        for(int i = 0; i < words.size(); i++){
            int mask = 0;
            for(int j = 0; j < words[i].size(); j++){
                mask = mask | (1 << (words[i][j]-'a'));
            }
            if(hash.count(mask) != 0){
                ds.unify(i, hash[mask]);
            }
            else{
                hash[mask] = i;
            }
            masks[i] = mask;
        }
        for(int i = 0; i < masks.size(); i++){
            for(int j = 0; j < 26; j++){
                if(masks[i] & (1 << j)){
                    if(hash.find(masks[i] - (1 << j)) == hash.end()){
                        hash[masks[i] - (1 << j)] = i;
                    }
                    else{
                        ds.unify(i, hash[masks[i] - (1 << j)]);
                    }
                }
            }
        }
        int sizeN = 0;
        for(int i = 0; i < words.size(); i++){
            sizeN = max(sizeN, ds.componentSize(i));
        }
        return {ds.components(), sizeN};
    }
};