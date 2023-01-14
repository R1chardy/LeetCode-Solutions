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
        if(root1 > root2){
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
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind ds(26);
        for(int i = 0; i < s1.length(); i++){
            ds.unify(s1[i]-'a', s2[i]-'a');
        }
        string s = "";
        for(int i = 0; i < baseStr.length(); i++){
            s = s + (char)(ds.find(baseStr[i]-'a')+'a');
        }
        return s;
    }
};