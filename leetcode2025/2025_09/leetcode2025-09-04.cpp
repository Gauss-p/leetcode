#include <iostream>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        return abs(x-z)==abs(y-z) ? 0 : (abs(x-z)<abs(y-z) ? 1 : 2);
    }
};

int main(){
    Solution s;
    int x=2, y=7, z=4;
    cout << s.findClosest(x, y, z) << endl;
}
