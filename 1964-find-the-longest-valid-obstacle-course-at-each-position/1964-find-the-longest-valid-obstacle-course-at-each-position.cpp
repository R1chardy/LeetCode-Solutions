class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ret;
        vector<int> piles;
        for(int obstacle : obstacles){
            int i = upper_bound(piles.begin(), piles.end(), obstacle) - piles.begin();
            if(i == piles.size()){
                piles.push_back(obstacle);
            }
            else{
                piles[i] = obstacle;
            }
            ret.push_back(i + 1);
        }
        return ret;
    }
};