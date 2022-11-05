class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0, prev = nums[0];
        for(auto x : nums){
            if(x == prev){
                count++;
                if(count > nums.size()/2){
                    return x;
                }
            }
            else{
                count = 1;
                prev = x;
            }
        }
        return -1;
    }
};