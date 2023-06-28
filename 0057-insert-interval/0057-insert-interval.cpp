class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int leftb = INT_MAX, rightb = -1;
        bool pushed = false;
        for(auto& intv : intervals){
            if(intv[1] < newInterval[0] || intv[0] > newInterval[1]){
                if(!pushed && leftb != INT_MAX && rightb != -1){
                    ans.push_back({leftb, rightb});
                    pushed = true;
                    leftb = INT_MAX;
                    rightb = -1;
                }
                else if(!pushed && intv[0] > newInterval[1]){
                    ans.push_back(newInterval);
                    pushed = true;
                }
                ans.push_back(intv);
            }
            else{
                leftb = min(leftb, min(intv[0], newInterval[0]));
                rightb = max(rightb, max(intv[1], newInterval[1]));
            }
        }
        if(!pushed){
            if(leftb == INT_MAX && rightb == -1){
                ans.push_back(newInterval);
            }
            else{
                ans.push_back({leftb, rightb});
            }
        }
        return ans;
    }
};