class Solution {
public:
    struct TrieNode{
        string val;
        bool isEnd;
        TrieNode* next[26];
        TrieNode(){
            isEnd = false;
            for(int i = 0; i < 26; i++){
                next[i] = nullptr;
            }
        }
    };
        
    void insert(string s){
        TrieNode* temp = root;
        for(auto c : s){
            if(temp->next[c-'a'] == nullptr){
                temp->next[c-'a'] = new TrieNode();
            }
            temp = temp->next[c-'a'];
        }
        temp->val = s;
        temp->isEnd = true;
    }
    
    void dfs(vector<vector<char>>& board, vector<string>& res, int i, int j, TrieNode* root){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*' 
           || root->next[board[i][j]-'a'] == nullptr){
            return;
        }
        root = root->next[board[i][j]-'a'];
        if(root->isEnd){
            res.push_back(root->val);
            root->isEnd = false;
        }
        char temp = board[i][j];
        board[i][j] = '*';
        dfs(board, res, i+1, j, root);
        dfs(board, res, i-1, j, root);
        dfs(board, res, i, j+1, root);
        dfs(board, res, i, j-1, root);
        board[i][j] = temp;
    }
    
    TrieNode* root = new TrieNode();
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        for(auto x : words){
            insert(x);
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(board, res, i, j, root);
            }
        }
        return res;
    }
};