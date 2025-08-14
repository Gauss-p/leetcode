#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n){
            if (n%3 == 2){
                return false;
            }
            n /= 3;
        }
        return true;
    }
};

int main(){
    Solution s;
    int n = 12;
    cout << s.checkPowersOfThree(n) << endl;
}
