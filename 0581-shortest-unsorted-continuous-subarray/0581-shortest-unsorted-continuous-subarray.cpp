class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> dec;
        stack<int> inc;
        int first = nums.size();
        int last = -1;
        for(int i = 0; i < nums.size(); i++){
            while(!inc.empty() && nums[i] < nums[inc.top()]){
                first = min(first, inc.top());
                inc.pop();
            }
            inc.push(i);
        }
        
        for(int i = nums.size() - 1; i >= 0; i--){
            while(!dec.empty() && nums[i] > nums[dec.top()]){
                last = max(last, dec.top());
                dec.pop();
            }
            dec.push(i);
        }
        cout << first << " " << last;
        if(first == nums.size() && last == -1){
            return 0;
        }
        else{
            return last - first + 1;
        }
    }
};