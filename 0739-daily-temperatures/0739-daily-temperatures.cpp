class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> tStack;
        vector<int> ans = vector<int>(temperatures.size(), 0);
        int temp;
        
        for(int i = 0; i < temperatures.size(); i++){
            while(!tStack.empty() && temperatures[i] > temperatures[tStack.top()]){
                temp = tStack.top();
                tStack.pop();
                ans[temp] = i - temp;
            }
            tStack.push(i);
        }
        return ans;
        
    }
};