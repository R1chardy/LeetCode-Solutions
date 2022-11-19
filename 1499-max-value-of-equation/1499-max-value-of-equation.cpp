class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;   //diff, xval
        int maxV = INT_MIN;
        for(auto x : points){
            while(!pq.empty() && x[0] - pq.top().second  > k){
                pq.pop();
            }
            if(!pq.empty()){
                maxV = max(maxV, x[0] + x[1] + pq.top().first);
            }
            pq.push({x[1] - x[0], x[0]});
        }
        return maxV;
    }
};