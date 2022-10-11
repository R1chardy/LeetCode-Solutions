class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points){
        vector<int> edges(1001, 0);
        int count = 0;
        int index;
        int minV;
        for(int i = 0; i < points.size(); i++){
            edges[i] = abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]);
        }
        edges[0] = INT_MAX;
        for(int j = 1; j < points.size(); j++){
            minV = INT_MAX;
            index = 0;
            for(int i = 0; i < points.size(); i++){
                if(edges[i] < minV){
                    minV = edges[i];
                    index = i;
                }
            }
            edges[index] = INT_MAX;
            count += minV;
            for(int i = 0; i < points.size(); i++){
                if(edges[i] != INT_MAX){
                    edges[i] = min(edges[i], abs(points[index][0] - points[i][0]) 
                                            + abs(points[index][1] - points[i][1]));
                }
            }
        }
        return count;
    }
};