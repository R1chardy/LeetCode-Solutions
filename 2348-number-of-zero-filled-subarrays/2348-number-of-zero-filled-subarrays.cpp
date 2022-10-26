class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int count = 0;
        long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                count++;
                sum += count;
            }
            else{
                count = 0;
            }
        }
        return sum;
    }
};