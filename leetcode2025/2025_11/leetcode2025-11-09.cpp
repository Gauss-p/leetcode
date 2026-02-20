#include <iostream>
using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int res = 0;
        while (num1 != 0 && num2 != 0){
            if (num1 >= num2){
                res += num1/num2;
                num1 %= num2;
            }
            else{
                res += num2/num1;
                num2 %= num1;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int num1 = 2, num2 = 3;
    cout << s.countOperations(num1, num2) << endl;
}
