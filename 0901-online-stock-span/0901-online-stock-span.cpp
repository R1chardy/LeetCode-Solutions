class StockSpanner {
public:
    stack<pair<int, int>> p;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        while(!p.empty() && p.top().first <= price){
            count += p.top().second;                
            p.pop();
        }
        p.push({price, count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */