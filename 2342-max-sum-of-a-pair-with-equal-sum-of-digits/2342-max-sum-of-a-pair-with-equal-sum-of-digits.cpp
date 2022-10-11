class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int temp;
        int maxA = -1;
        unordered_map<int, priority_queue<int>> pre;
        for(int i = 0; i < nums.size(); i++){
            temp = sod(nums[i]);
            pre[temp].push(nums[i]);
        }
        for(auto x : pre){
            temp = 0;
            if(x.second.size() > 1){
                temp += x.second.top();
                x.second.pop();
                temp += x.second.top();
                maxA = max(maxA, temp);
            }
        }
        return maxA;
    }
    
    int sod(int n){
        int sum = 0;
        while(n != 0){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
};