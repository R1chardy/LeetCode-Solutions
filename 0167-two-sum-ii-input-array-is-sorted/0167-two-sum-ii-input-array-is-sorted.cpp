class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> ret;
        int temp;
        while(l < r){
            temp = numbers[l] + numbers[r];
            if(temp > target){
                r--;
            }
            else if(temp < target){
                l++;
            }
            else{
                break;
            }
        }
        ret.push_back(l+1);
        ret.push_back(r+1);
        return ret;
    }
};