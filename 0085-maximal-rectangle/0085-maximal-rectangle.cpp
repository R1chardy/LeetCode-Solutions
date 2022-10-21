class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxV = 0;
        vector<int> rows(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '0'){
                    rows[j] = 0;
                }
                else{
                    rows[j] += 1;
                }
            }
            maxV = max(maxV, largestRectangleArea(rows));
        }
        return maxV;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> inc;
        int currMax = 0;
        int area = 0;
        int currI;
        int prevI;
        for(int i = 0; i <= heights.size(); i++){
            while(!inc.empty() && (i == heights.size() || heights[i] < heights[inc.top()])){
                currI = inc.top();
                inc.pop();
                prevI = inc.empty()? -1 : inc.top();
                area = heights[currI] * (i - prevI - 1);
                if(area > currMax){
                    currMax = area;
                }
            }
            inc.push(i);
        }
        return currMax;
    }
};