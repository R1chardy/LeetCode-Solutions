class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minV = INT_MAX, ret = -1;
        for(int i = 0; i < points.size(); i++){
            if((points[i][0] == x || points[i][1] == y) && abs(y-points[i][1]) + abs(x-points[i][0]) < minV){
                minV = abs(y-points[i][1]) + abs(x-points[i][0]);
                ret = i;
            }
        }
        return ret;
    }
};