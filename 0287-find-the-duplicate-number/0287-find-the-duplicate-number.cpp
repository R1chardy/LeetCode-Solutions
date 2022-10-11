class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], slow2 = nums[0], fast = nums[0];
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                break;
            }
        }
        cout << slow << " " << fast << endl;
        while(slow != slow2){
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};