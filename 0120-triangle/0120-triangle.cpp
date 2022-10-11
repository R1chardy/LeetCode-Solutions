class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle[triangle.size() - 1]);
        int row = triangle.size() - 2;
        int index = 0;
        while(row >= 0){
            while(index < triangle[row].size()){
                dp[index] = min(triangle[row][index] + dp[index], 
                                triangle[row][index] + dp[index + 1]);
                index++;
            }
            row--;
            index = 0;
        }
        return dp[0];
    }
};