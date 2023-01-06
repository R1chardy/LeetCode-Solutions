class Solution {
public:
    int maximumGap(vector<int>& nums) {
        queue<int> buckets[10];
        long exp = 1;
        for(int i = 0; i < 10; i++){
            for(auto x : nums){
                buckets[x/exp%10].push(x);
            }
            exp *= 10;
            nums.clear();
            for(int j = 0; j < 10; j++){
                while(!buckets[j].empty()){
                    nums.push_back(buckets[j].front());
                    buckets[j].pop();
                }
            }
        }
        int diff = 0;
        for(int i = 1; i < nums.size(); i++){
            diff = max(diff, nums[i] - nums[i-1]);
        }
        return diff;
    }
};