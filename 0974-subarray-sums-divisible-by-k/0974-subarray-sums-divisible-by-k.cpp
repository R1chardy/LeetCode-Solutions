class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> pre;
        int s = 0;
        for(int i = 0; i < nums.size(); i++){
            pre.push_back(s);
            s += nums[i];
        }
        pre.push_back(s);
        
        unordered_map<int,int> xd;
        xd[0]=1;
        int count = 0;
        for(int i = 1; i < pre.size(); i++){
            int idx = pre[i]%k < 0? pre[i]%k + k : pre[i]%k;
            count += xd[idx];
            xd[idx]++;
        }
        return count;
    }
};