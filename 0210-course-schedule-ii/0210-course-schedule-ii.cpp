class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> indegs(numCourses);
        unordered_map<int,vector<int>> mp;
        unordered_set<int> visited;
        vector<int> ret;
        for(auto& prereq : prerequisites){
            indegs[prereq[0]]++;
            mp[prereq[1]].push_back(prereq[0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(indegs[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            if(visited.count(top)){
                continue;
            }
            ret.push_back(top);
            visited.insert(top);
            for(auto& node : mp[top]){
                indegs[node]--;
            }
            for(int i = 0; i < numCourses; i++){
                if(indegs[i] == 0 && visited.count(i) == 0){
                    q.push(i);
                }
            }
            
        }
        return visited.size() == numCourses? ret : vector<int>();
    }
};