class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> dec;
        vector<int> res = vector<int>(nums.size(), -1);
        for(int i = 0; i < nums.size() * 2; i++){
            while(!dec.empty() && nums[i%nums.size()] > nums[dec.top()]){
                res[dec.top()] = nums[i%nums.size()];
                dec.pop();
            }
            dec.push(i%nums.size());
        }
        return res;
    }
};