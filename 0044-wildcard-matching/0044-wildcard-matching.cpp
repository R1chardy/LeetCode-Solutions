class Solution {
public:
    bool isMatch(string s, string p) {
        bool arr[s.length()+1][p.length()+1];
        for(int i = 0; i < s.length()+1; i++){
            for(int j = 0; j < p.length()+1; j++){
                arr[i][j] = false;
            }
        }
        arr[0][0] = true;
        for(int j = 1; j < p.length()+1; j++){
            if(p[j-1] == '*'){
                arr[0][j] = arr[0][j-1];
            }
        }
        for(int i = 1; i < s.length()+1; i++){
            for(int j = 1; j < p.length()+1; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    arr[i][j] = arr[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    arr[i][j] = arr[i-1][j] || arr[i][j-1];
                }
            }
        }
        return arr[s.length()][p.length()];
    }
};