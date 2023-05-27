class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        int l1, r1, l2, r2;
        vector<vector<int>> ans;
        while(i < firstList.size() && j < secondList.size()){
            l1 = firstList[i][0], r1 = firstList[i][1];
            l2 = secondList[j][0], r2 = secondList[j][1];
            if(r1 < l2){
                i++;
            }
            else if(r2 < l1){
                j++;
            }
            else if(r1 <= r2 && l1 >= l2){
                ans.push_back({l1,r1});
                i++;
            }
            else if(r2 <= r1 && l2 >= l1){
                ans.push_back({l2,r2});
                j++;
            }
            else if(r1 >= l2 && r1 <= r2){
                ans.push_back({l2,r1});
                i++;
            }
            else{
                ans.push_back({l1,r2});
                j++;
            }
        }
        return ans;
    }
};