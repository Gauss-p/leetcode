#include <iostream>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double part = 1.0*minutes/60;
        double hd = (hour%12)*30.0+30*part;
        double md = minutes*6.0;
        double res = abs(hd-md);
        return min(res, 360-res);
    }
};

int main(){
    Solution s;
    int hour = 12, minutes = 30;
    cout << s.angleClock(hour, minutes) << endl;
}
