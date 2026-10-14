#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9*num){
            return "";
        }
        string res = (sum/9>0 ? string(sum/9, '9') : "")+to_string(sum%9)+(num-(sum/9+1)>0 ? string(num-(sum/9+1), '0') : "");
        return res.substr(0, num);
    }
};

int main(){
    Solution s;
    int num = 3, sum = 15;
    cout << s.maxSumOfSquares(num, sum) << endl;
}
