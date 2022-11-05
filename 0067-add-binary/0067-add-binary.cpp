class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.length()-1;
        int j = b.length()-1;
        int sum, carry = 0;
        while(i >= 0 && j >= 0){
            sum = (a[i]-'0') + (b[j]-'0') + carry;
            ans = (char)(sum%2+'0') + ans;
            carry = sum/2;
            i--;
            j--;
        }
        while(i >= 0){
            sum = (a[i]-'0') + carry;
            ans = (char)(sum%2+'0') + ans;
            carry = sum/2;
            i--;
        }
        while(j >= 0){
            sum = (b[j]-'0') + carry;
            ans = (char)(sum%2+'0') + ans;
            carry = sum/2;
            j--;
        }
        if(carry){
            ans = '1' + ans;
        }
        return ans;
    }
};