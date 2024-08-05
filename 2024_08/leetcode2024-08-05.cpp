#include <iostream>
using namespace std;

class Solution {
public:
    int findIntegers(int n) {
        if (n == 0 || n == 1) return n+1;
        int length = 0;
        while (n >> length){
            length++;
        }
        int first = 1, second = 1;
        for (int _=0; _<length; _++){
            int tmp = first+second;
            first = second;
            second = tmp;
        }
        int res;
        if (length >= 2 && ((n >> (length-2))&1)){
            return second;
        }
        if (abs(n-(1<<(length-1))) < abs(n-(1<<(length-2)))){
            res = first;
            for (int i=(1<<(length-1)); i<=n; i++){
                if ((i & (i<<1)) == 0){
                    res++;
                }
            }
        }
        else{
            res = second;
            for (int i=n; i<(1<<length); i++){
                if ((i & (i<<1)) == 0){
                    res--;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 1000000000;
    cout << s.findIntegers(n) << endl;
}
