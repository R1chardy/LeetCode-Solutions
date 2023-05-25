class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int,vector<int>> mp;
        for(auto& edge : edges){
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        unordered_set<int> bad(restricted.begin(), restricted.end());
        unordered_set<int> visited;
        q.push(0);
        int nodes = 0;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            visited.insert(top);
            nodes++;
            for(auto& n : mp[top]){
                if(bad.count(n) == 0 && visited.count(n) == 0){
                    q.push(n);
                }
            }
        }
        return nodes;
    }
};