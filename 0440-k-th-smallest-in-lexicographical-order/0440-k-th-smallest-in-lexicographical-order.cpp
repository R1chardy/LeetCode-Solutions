class Solution {
public:
    int findKthNumber(int n, int k) {
    int curr = 1;
    k--;
    while (k > 0) {
        long long first = curr, last = curr + 1;
        long long step = 0;
        while (first <= n) {
            step += min((long long)n + 1, last) - first;
            first *= 10;
            last *= 10;
        }
        if (k >= step) {
            curr++;
            k -= step;
        } else {
            curr *= 10;
            k--;
        }
    }
    return curr;
}

};