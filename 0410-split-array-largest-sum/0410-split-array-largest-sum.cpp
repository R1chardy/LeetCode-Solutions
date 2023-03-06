class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = nums[0], right = 0;
        for(int x : nums){
            left = max(left, x);
            right += x;
        }
        return solve(nums, k, left, right);
    }
    
    int solve(vector<int>& nums, int k, int left, int right){
        while(left < right){
            int mid = (left + right) / 2;
            int buckets = parse(nums, mid);
            if(buckets > k){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
    
    int parse(vector<int>& nums, int k){
        int currSum = 0, count = 1;
        for(int x : nums){
            if(currSum + x > k){
                currSum = x;
                count++;
            }
            else{
                currSum += x;
            }
        }
        return count;
    }
};