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
    
    int components() const{
        return numComp;
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        UnionFind ds(strs.size());
        for(int i = 0; i < strs.size(); i++){
            for(int j = i+1; j < strs.size(); j++){
                if(isSimilar(strs[i], strs[j])){
                    ds.unify(i, j);
                }
            }
        }
        return ds.components();
    }
    
    bool isSimilar(string a, string b){
        if(a == b){
            return true;
        }
        else if(a.length() != b.length()){
            return false;
        }
        else{
            int i = 0, count = 0;
            while(i < a.length()){
                if(a[i] != b[i]){
                    count++;
                }
                i++;
                if(count > 2){
                    return false;
                }
            }   
            if(count != 2){
                return false;
            }
            return true;
        }
    }
};