#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0){
            return true;
        }
        for (int a=0; a<sqrt(c); a++){
            int b = c-a*a;
            int tmp = sqrt(b);
            if (tmp*tmp == b){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    int c = 2000000;
    cout << s.judgeSquareSum(c) << endl;
}
