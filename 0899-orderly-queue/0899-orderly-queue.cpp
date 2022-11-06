class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k >= 2){
            sort(s.begin(), s.end());
            return s;
        }
        else{
            string minS = s;
            for(int i = 0; i < s.length(); i++){
                minS = min(minS, s.substr(i) + s.substr(0, i));
            }
            return minS;
        }
    }
};