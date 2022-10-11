class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> rems = {{0,1}};
        
        vector<int> prefix(nums.size()+1, 0);
        prefix[0]=0;
        int pre = 0;
        for(int i = 0; i < nums.size(); i++){
            pre += nums[i];
            prefix[i+1] = pre;
        }
        
        for(auto x : prefix){
            cout << x << " ";
        }
        
        int count = 0;
        for(int i = 1; i < prefix.size(); i++){
            count += rems[prefix[i]%k < 0? prefix[i]%k + k : prefix[i]%k];
            rems[prefix[i]%k < 0? prefix[i]%k + k : prefix[i]%k]++;
        }
        return count;
    }
};