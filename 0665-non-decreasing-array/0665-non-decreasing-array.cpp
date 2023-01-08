class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int faults = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                faults++;
                if(i <= 1){
                    nums[i-1] = nums[i];
                }
                else{
                    if(nums[i-2] <= nums[i-1] && nums[i-2] <= nums[i]){
                        nums[i-1] = nums[i];
                    }
                    else{
                        nums[i] = nums[i-1];
                    }
                }
            }
            if(faults > 1){
                return false;
            }
        }
        return true;
    }
};