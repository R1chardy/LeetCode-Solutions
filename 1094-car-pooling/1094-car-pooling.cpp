class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int size = 0;
        unordered_map<int, int> locs;
        for(int i = 0; i < trips.size(); i++){
            locs[trips[i][1]] += trips[i][0];
            locs[trips[i][2]] -= trips[i][0];
        }
        for(int i = 0; i < locs.size(); i++){
            size += locs[i];
            if(size > capacity){
                return false;
            }
        }
        return true;
    }
};