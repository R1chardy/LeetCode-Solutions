class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> possible(wordList.begin(), wordList.end());
        q.push(beginWord);
        int depth = 0, width = 1;
        while(!q.empty()){
            string s1 = q.front();
            q.pop();
            width--;
            if(s1 == endWord){
                return depth+1;
            }
            for(int i = 0; i < s1.length(); i++){
                string word = s1;
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(possible.count(word)){
                        q.push(word);
                        possible.erase(word);
                    }
                }
            }
            if(width <= 0){
                width = q.size();
                depth++;
            }
        }
        return 0;
    }
};