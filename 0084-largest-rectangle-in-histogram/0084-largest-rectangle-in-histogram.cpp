class Solution {
public:
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