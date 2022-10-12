class Solution {
public:
    string addBinary(string a, string b) {
        int maxL = max(a.length(), b.length());
        char as, bs;
        string ret;
        int carry = 0, sum, ap = a.length()-1, bp = b.length()-1;
        for(int i = 0; i < maxL; i++){
            if(ap-i >= 0){
                as = a[ap-i];
            }
            else{
                as = '0';
            }
            if(bp-i >= 0){
                bs = b[bp-i];
            }
            else{
                bs = '0';
            }
            sum = (as-'0' + bs-'0' + carry);
            ret = to_string(sum%2) + ret;
            carry = sum/2;
        }
        if(carry){
            ret = '1' + ret;
        }
        return ret;
    }
};