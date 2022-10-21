class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        stack<int> inc;
        int currMax = 0;
        int area = 0;
        int currI;
        int prevI;
        for(int i = 0; i <= nums.size(); i++){
            while(!inc.empty() && (i == nums.size() || nums[i] < nums[inc.top()])){
                currI = inc.top();
                inc.pop();
                prevI = inc.empty()? -1 : inc.top();
                area = nums[currI] * (i - prevI - 1);
                if(area > currMax && prevI+1 <= k && k <= i-1){
                    currMax = area;
                }
            }
            inc.push(i);
        }
        return currMax;
    }
};