class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxL = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<double,int> slopes;
            for(int j = i+1; j < points.size(); j++){
                if(points[j][0] == points[i][0]){
                    maxL = max(maxL, ++slopes[INT_MAX]);;
                }
                else{
                    maxL = max(maxL, ++slopes[((double)(points[j][1]-points[i][1]))/(points[j][0]-points[i][0])]);   
                }
            }
        }
        return ++maxL;
    }
};