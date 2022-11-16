class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int, int> xd;
        for(int i = 0; i < difficulty.size(); i++){
            if(xd.count(difficulty[i])){
                xd[difficulty[i]] = max(xd[difficulty[i]], profit[i]);
            }
            else{
                xd.emplace(difficulty[i], profit[i]);
            }
        }
        int temp = xd[0];
        for(auto& x : xd){
            x.second = temp = max(x.second, temp);
        }
        cout << endl;
        sort(difficulty.begin(), difficulty.end());
        int sum = 0, maxL;
        for(int i = 0; i < worker.size(); i++){
            auto it = upper_bound(difficulty.begin(), difficulty.end(), worker[i]);
            if(it == --difficulty.end() && *it <= worker[i]){
                sum += xd[*it];
            }
            else if(it != difficulty.begin()){
                it--;
                maxL = xd[*it];
                // while(it != difficulty.begin()){
                //     it--;
                //     maxL = max(maxL, xd[*it]);
                // }
                sum += maxL;
            }
        }
        return  sum;
    }
};