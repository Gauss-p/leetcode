class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0){
            return "0";
        }
        string res;
        while (n != 1){
            if (n % (-2) == -1){
                res += '1';
                n = n/(-2)+1;
            }
            else{
                res += to_string(n%(-2));
                n = n/(-2);
            }
        }
        res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
