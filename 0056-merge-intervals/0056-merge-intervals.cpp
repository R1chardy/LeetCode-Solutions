class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(auto interval : intervals){
            if(interval[1] <= right){
                continue;
            }
            if(interval[0] <= right){
                right = interval[1];
            }
            else if(interval[0] > right){
                ans.push_back({left,right});
                left = interval[0];
                right = interval[1];
            }
        }
        if(ans.size() == 0){
            ans.push_back({left,right});
            return ans;
        }
        auto b = ans.back();
        if(b[0] != left || b[1] != right){
            ans.push_back({left,right});
        }
        return ans;
    }
};