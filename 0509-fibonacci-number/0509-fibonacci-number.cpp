class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }
        int num1 = 1;
        int num2 = 1;
        int ans = 1;
        for(int i = 2; i < n; i++){
            num1 = num2;
            num2 = ans;
            ans = num1 + num2;
        }
        return ans;
    }
};