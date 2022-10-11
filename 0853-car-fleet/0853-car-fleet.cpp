class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,int> carMap;
        vector<int> sortPosition = position;
        for(int i = 0; i < position.size(); i++){
            carMap[position[i]] = speed[i];
        }
        sort(sortPosition.begin(), sortPosition.end());
        
        stack<double> sStack;
        
        for(int i = position.size() - 1; i >= 0; i--){
            double time = (target - sortPosition[i]) / (double)carMap[sortPosition[i]];
            if(!sStack.empty()){
                if(time > sStack.top()){
                    sStack.push(time);
                }
            }
            else{
                sStack.push(time);
            }
        }
        
        return sStack.size();
    }
};