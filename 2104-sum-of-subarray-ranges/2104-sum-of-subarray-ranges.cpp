class Solution {
public:
    long long subArrayRanges(vector<int>& nums){
        long long sum = 0;
        stack<int> dec;
        stack<int> inc;
        for(int i = 0; i <= nums.size(); i++){
            sum += getMaxVal(nums, dec, i) 
                - getMinVal(nums, inc, i);
        }
        return sum;
    }
    
    long long getMaxVal(vector<int>& nums, stack<int>& dec, int i){
        long long curr;
        long long prev;
        long long sum = 0;
        while(!dec.empty() && (i == nums.size() || nums[i] > nums[dec.top()])){
            curr = dec.top();
            dec.pop();
            prev = dec.empty()? -1 : dec.top();
            sum += (i - curr) * (curr - prev) * nums[curr];
        }
        dec.push(i);
        return sum;
    }
    
    long long getMinVal(vector<int>& nums, stack<int>& inc, int i){
        long long curr;
        long long prev;
        long long sum = 0;
        while(!inc.empty() && (i == nums.size() || nums[i] < nums[inc.top()])){
            curr = inc.top();
            inc.pop();
            prev = inc.empty()? -1 : inc.top();
            sum += (i - curr) * (curr - prev) * nums[curr];
        }
        inc.push(i);
        return sum;
    }
    
};