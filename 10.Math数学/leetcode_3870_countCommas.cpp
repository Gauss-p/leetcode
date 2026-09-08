#include <iostream>
using namespace std;

class Solution {
public:
    int countCommas(int n) {
        return max(n-999, 0);
    }
};

int main(){
    Solution s;
    int n = 1002;
    cout << s.countCommas(n) << endl;
}
