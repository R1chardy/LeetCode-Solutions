class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> inc;
        int next, prev;
        long ans = 0;
        int mod = 1e9+7;
        for(int i = 0; i <= arr.size(); i++){
            while(!inc.empty() && (i == arr.size() || arr[i] < arr[inc.top()])){
                next = inc.top();
                inc.pop();
                prev = inc.empty()? -1 : inc.top();
                ans += ((long)(next-prev)*(long)(i-next)*(long)arr[next])%mod;
                ans %= mod;
            }
            inc.push(i);
        }
        return ans;
    }
};