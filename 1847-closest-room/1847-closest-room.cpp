class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        sort(rooms.begin(), rooms.end(), [](auto& a, auto& b){
            return a[1] > b[1];
        });
        for(int i = 0; i < queries.size(); i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](auto& a, auto& b){
            return a[1] > b[1];
        });
        int i = 0;
        set<int> st;
        vector<int> ans(queries.size());
        for(auto& query : queries){
            int prefId = query[0];
            int prefSize = query[1];
            int idx = query[2];
            while(i < rooms.size() && rooms[i][1] >= prefSize){
                st.emplace(rooms[i][0]);
                i++;
            }
            if(st.size() == 0){
                ans[idx] = -1;
                continue;
            }
            int ret;
            auto val = st.upper_bound(prefId);
            if(val != st.begin()){
                int a = *val;
                int b = *(--val);
                if(abs(a-prefId) < abs(b-prefId)){
                    ret = a;
                }
                else if(abs(a-prefId) > abs(b-prefId)){
                    ret = b;
                }
                else{
                    ret = a < b? a : b;
                }
            }
            else{
                ret = *val;
            }
            ans[idx] = ret;
        }
        return ans;
    }
};