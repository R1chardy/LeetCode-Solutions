class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, double>> dMap;   //index to distance
        vector<vector<int>> ans;
        for(int i = 0; i < points.size(); i++){
            dMap.push_back({i, getDist(points[i])});
        }
        sort(dMap.begin(), dMap.end(), [](auto x, auto y){
            return x.second < y.second;
        });
        for(int i = 0; i < k; i++){
            ans.push_back({points[dMap[i].first]});
        }
        return ans;
    }
    
    double getDist(vector<int>& coords){
        return sqrt(coords[0]*coords[0] + coords[1]*coords[1]);
    }
};