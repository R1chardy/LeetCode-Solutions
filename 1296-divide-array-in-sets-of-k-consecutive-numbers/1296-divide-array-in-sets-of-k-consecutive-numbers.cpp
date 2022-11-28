class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto x : nums){
            mp[x]++;
        }
        int temp;
        for(auto x : mp){
            if(mp[x.first] > 0){
                temp = mp[x.first];
                for(int i = x.first; i < x.first+k; i++){
                    mp[i] -= temp;
                    if(mp[i] < 0){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};