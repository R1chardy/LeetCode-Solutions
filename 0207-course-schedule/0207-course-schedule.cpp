class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        for(auto& p : prerequisites){
            mp[p[1]].push_back(p[0]);
        }
        vector<bool> visited(numCourses);
        vector<bool> curStack(numCourses);
        for(int i = 0; i < numCourses; i++){
            if(containsCycle(i, mp, visited, curStack)){
                return false;
            }
        }
        return true;
    }
    
    bool containsCycle(int i, unordered_map<int,vector<int>>& mp, vector<bool>& visited, vector<bool>& curStack){
        if(visited[i] && curStack[i]){
            return true;
        }
        visited[i] = true;
        curStack[i] = true;
        for(auto& c : mp[i]){
            if(containsCycle(c, mp, visited, curStack)){
                return true;
            }
        }
        curStack[i] = false;
        mp[i].clear();
        return false;
    }
};