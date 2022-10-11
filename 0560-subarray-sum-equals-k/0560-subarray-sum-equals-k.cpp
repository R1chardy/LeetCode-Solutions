class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> pre;
        int temp = 0;
        int count = 0;
        pre[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            temp += nums[i];
            count += pre[temp - k];
            pre[temp]++;
        }
        return count;
    }
};