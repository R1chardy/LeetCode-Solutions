class StockSpanner {
public:
    stack<pair<int, int>> dec;
    int count;
    StockSpanner() {
        
    }
    
    int next(int price) {
        count = 1;
        while(!dec.empty() && price >= dec.top().first){
            count += dec.top().second;
            dec.pop();
        }
        dec.push({price, count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */