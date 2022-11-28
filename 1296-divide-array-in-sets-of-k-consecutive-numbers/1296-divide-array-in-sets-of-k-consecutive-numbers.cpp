class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto x : nums){
            mp[x]++;
        }
        for(auto x : mp){
            while(mp[x.first] > 0){
                for(int i = x.first; i < x.first+k; i++){
                    mp[i]--;
                    if(mp[i] < 0){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};