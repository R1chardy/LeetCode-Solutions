class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ret;
        multiset<int, greater<int>> q{0};
        vector<pair<int, int>> edges;
        for(auto x : buildings){
            edges.push_back({x[0], x[2]});
            edges.push_back({x[1], -x[2]});
        }
        
        sort(edges.begin(), edges.end(), [](auto x, auto y){
            return x.first == y.first? x.second > y.second : x.first < y.first;
        });
        
        int prev = 0;
        for(int i = 0; i < edges.size(); i++){
            if(edges[i].second > 0){
                q.insert(edges[i].second);
            }
            else{
                q.erase(q.find(-edges[i].second));
            }
            if(*q.begin() != prev){
                ret.push_back(vector<int>{edges[i].first, *q.begin()});
                prev = *q.begin();
            }
        }
        return ret;
    }
};