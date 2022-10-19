class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mask = 0;
        int result = 0;
        int count = 0;
        for(int j = 31; j >= 0; j--){
            mask = 1<<j;
            count = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] & mask){
                    count++;
                }
            }
            result = result<<1;
            if(count % 3){
                result += 1;
            }
        }
        return result;
    }
};
