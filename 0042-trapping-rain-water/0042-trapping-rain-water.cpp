class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = 0;
        while(l < height.size() && height[l] == 0){
            l++;
        }
        int sum = 0;
        for(r = l+1; r < height.size(); r++){
            if(height[r] > height[l]){
                for(int i = l+1; i < r; i++){
                    sum += height[l] - height[i];
                }
                l = r;
            }
        }
        
        r = height.size()-1;
        while(r < height.size() && height[r] == 0){
            r--;
        }
        for(l = r-1; l >= 0; l--){
            if(height[l] >= height[r]){
                for(int i = r-1; i > l; i--){
                    sum += height[r] - height[i];
                }
                r = l;
            }
        }
        
        return sum;
    }
};