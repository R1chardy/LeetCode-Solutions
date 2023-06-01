class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>> mp;
        for(auto& edge : edges){
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        visited.emplace(0);
        int ans = solve(0, mp, visited, hasApple);
        return ans == 0? 0 : ans-2;
    }
    
    int solve(int idx, unordered_map<int,vector<int>>& mp, unordered_set<int>& visited, vector<bool>& hasApple){
        int sum = 0;
        for(auto& num : mp[idx]){
            if(visited.count(num) == 0){
                visited.emplace(num);
                sum += solve(num, mp, visited, hasApple);
            }
        }
        if(hasApple[idx]){
            return sum == 0? 2 : 2 + sum;
        }
        else{
            return sum == 0? 0 : 2 + sum;
        }
    }
};