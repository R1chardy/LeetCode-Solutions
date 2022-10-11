class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int mid;
        int right = nums.size() - 1;
        while(left <= right){
            cout << "left is " << left << " right is " << right << "\n";
            mid = (left + right) / 2;
            if(target == nums[mid]){
                return mid;
            }
            else if(left == right){
                return -1;
            }
            if(nums[left] < nums[mid] && nums[mid] < nums[right]){
                if(target < nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else if(nums[left] < nums[mid] && nums[left] > nums[right]){
                if(target > nums[mid] || target < nums[left]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            else if(right - left + 1  == 2){
                left = nums[left] == target? left : right;
            }
            else{
                if(target < nums[mid] || target > nums[right]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};