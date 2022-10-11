struct TrieNode{
    
    char c = '0';
    vector<TrieNode*> neighbors;
    bool isEnd = false;
    TrieNode(char x = '0', bool y = false){
        c = x;
        isEnd = y;
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int i = 0;
        bool found = false;
        TrieNode* temp = root;
        while(i < word.length()){
            for(int j = 0; j < temp->neighbors.size(); j++){
                if(temp->neighbors[j]->c == word[i]){
                    temp = temp->neighbors[j];
                    found = true;
                    break;
                }
            }
            if(!found){
                temp->neighbors.push_back(new TrieNode(word[i]));
                temp = temp->neighbors[temp->neighbors.size() - 1];
            }
            found = false;
            i++;
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        int i = 0;
        TrieNode* temp = root;
        bool found = false;
        while(i < word.length()){
            for(int j = 0; j < temp->neighbors.size(); j++){
                if(temp->neighbors[j]->c == word[i]){
                    temp = temp->neighbors[j];
                    found = true;
                    break;
                }
            }
            if(!found){
                return false;
            }
            found = false;
            i++;
        }
        if(temp->isEnd){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        int i = 0;
        TrieNode* temp = root;
        bool found = false;
        while(i < prefix.length()){
            for(int j = 0; j < temp->neighbors.size(); j++){
                if(temp->neighbors[j]->c == prefix[i]){
                    temp = temp->neighbors[j];
                    found = true;
                    break;
                }
            }
            if(!found){
                return false;
            }
            found = false;
            i++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */