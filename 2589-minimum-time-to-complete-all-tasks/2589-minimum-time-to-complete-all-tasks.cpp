class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto& x, auto& y){
            return x[1] < y[1];
        });
        bool arr[2001] = {};
        for(auto& task : tasks){
            int duration = task[2];
            for(int i = task[0]; i <= task[1]; i++){
                if(duration <= 0){
                    break;
                }
                if(arr[i]){
                    duration--;
                }
            }
            for(int i = task[1]; i >= task[0]; i--){
                if(duration <= 0){
                    break;
                }
                if(!arr[i]){
                    arr[i] = true;
                    duration--;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < 2001; i++){
            if(arr[i]){
                count++;
            }
        }
        return count;
    }
};