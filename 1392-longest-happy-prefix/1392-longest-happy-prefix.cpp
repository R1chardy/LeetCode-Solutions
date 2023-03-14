class Solution {
public:
    string longestPrefix(string s) {
        int idx = KMP(s);
        return s.substr(0, idx);
    }
    
    int KMP(string s){
        int j = 0, i = 1;
        vector<int> arr(s.length(), 0);
        while(i < arr.size()){
            if(s[j] == s[i]){
                arr[i] = j + 1;
                i++;
                j++;
            }
            else{
                if(j > 0){
                    j = arr[j-1];
                }
                else{
                    arr[i] = 0;
                    i++;
                }
            }
        }
        return arr[s.length()-1];
    }
};