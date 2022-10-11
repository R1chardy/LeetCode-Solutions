class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;
        unordered_map<char, int> counts;
        for(int i = 0; i < t.length(); i++){
            tMap[t[i]] += 1;
            counts[t[i]] = 0;
        }
        int left = 0;
        int right = 0;
        int size = 0;
        int minLength = INT_MAX;
        pair<int, int> indices;
        while(right <= s.size() - 1){
            while(size < tMap.size() && right < s.length()){
                if(counts.find(s[right]) != counts.end()){
                    counts[s[right]] += 1;
                    if(counts[s[right]] == tMap[s[right]]){
                        size++;
                    }
                }
                right++;
            }
            while(size == tMap.size()){
                if(counts.find(s[left]) != counts.end()){
                    if(counts[s[left]] == tMap[s[left]]){
                        size--;
                    }
                    counts[s[left]]--;
                }
                left++;
            }
            if(right - left + 1 < minLength){
                minLength = right - left + 1;
                indices = {left, right};
            }
        }
        return indices.second == s.size() && indices.first == 0? "" : s.substr(indices.first - 1, minLength);
    }
};