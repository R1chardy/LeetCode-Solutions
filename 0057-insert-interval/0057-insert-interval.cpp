class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newI;
        int first = newInterval[0], last = newInterval[1];
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][1] < newInterval[0]){
                newI.push_back(intervals[i]);
            }
            else{
                first = min(intervals[i][0], newInterval[0]);
                int j = 0;
                for(j = i; j < intervals.size(); j++){
                    if(intervals[j][0] > newInterval[1]){
                        last = newInterval[1];
                        break;
                    }
                    else if(intervals[j][1] > newInterval[1]){
                        last = intervals[j][1];
                        j++;
                        break;
                    }
                }
                for(j; j < intervals.size(); j++){
                    newI.push_back(intervals[j]);
                }
                break;
            }
        }
        newI.push_back({first, last});
        sort(newI.begin(), newI.end());
        return newI;
    }
};