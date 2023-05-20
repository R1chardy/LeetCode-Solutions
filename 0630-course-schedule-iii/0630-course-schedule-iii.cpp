class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& a, auto&b){
            return a[1] < b[1];
        });
        int days = 0;
        priority_queue<int> pq;
        for(auto& course : courses){
            days += course[0];
            pq.push(course[0]);
            if(days > course[1]){
                days -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};