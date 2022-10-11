class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;
        while(r - l > 1){
            mid = (l + r) / 2;
            if(nums[l] > nums[r] && nums[r] > nums[mid] || nums[l] < nums[mid] && nums[mid] < nums[r]){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        return min(nums[l], nums[r]);
    }
};