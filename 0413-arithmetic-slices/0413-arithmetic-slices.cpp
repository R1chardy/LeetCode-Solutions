class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() <= 2){
            return 0;
        }
        int diff, prev_diff = nums[1] - nums[0], count = 1, sum = 0;
        for(int i = 2; i < nums.size(); i++){
            diff = nums[i]-nums[i-1];
            if(diff == prev_diff){
                count++;
            }
            else{
                sum += ((count - 1) * count) / 2;
                count = 1;
                prev_diff = diff;
            }
            
        }
        sum += ((count - 1) * count) / 2;
        return sum;
    }
};