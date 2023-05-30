class MyHashSet {
public:
    int bucketSize;
    vector<int> table[10007];
    hash<int> hasher;
    MyHashSet() {
        bucketSize = 10007;
    }
    
    void add(int key) {
        if(contains(key)){
            return;
        }
        int hashed = getHash(key);
        table[hashed].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)){
            return;
        }
        int hashed = getHash(key);
        table[hashed].erase(std::find(table[hashed].begin(), table[hashed].end(), key));
    }
    
    bool contains(int key) {
        int hashed = getHash(key);
        return find(key, hashed);
    }
    
    bool find(int key, int hashed){
        return std::find(table[hashed].begin(), table[hashed].end(), key) == table[hashed].end()? false : true;
    }
    
    int getHash(int key){
        return static_cast<int>(hasher(key)) % bucketSize;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */