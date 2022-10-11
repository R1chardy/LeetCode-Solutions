class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> counts;
        bool has[26] = {false};
        stack<char> tower;
        for(auto x : s){
            counts[x] += 1;
        }
        for(int i = 0; i < s.length(); i++){
            while(!tower.empty() && s[i] <= tower.top() && counts[tower.top()] != 0 && !has[s[i] - 'a']){
                cout << "popping " << tower.top() << "\n";
                has[tower.top() - 'a'] = false;
                tower.pop();
            }
            if(!has[s[i] - 'a']){
                cout << "pushing " << s[i] << "\n";
                has[s[i] - 'a'] = true;
                tower.push(s[i]);
            }
            counts[s[i]] -= 1;
        }
        string ret = "";
        while(!tower.empty()){
            ret = tower.top() + ret;
            tower.pop();
        }
        return ret;
    }
};