class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftP = 0;
        int rightP = height.size() - 1;
        int currArea = (rightP - leftP) * std::min(height[rightP], height[leftP]);
        while(rightP > leftP){
            if(height[rightP] < height[leftP]){
                rightP--;
            }
            else{
                leftP++;
            }
            if(((rightP - leftP) * std::min(height[rightP], height[leftP])) > currArea){
                currArea = (rightP - leftP) * std::min(height[rightP], height[leftP]);
            }
        }
        return currArea;
    }
};