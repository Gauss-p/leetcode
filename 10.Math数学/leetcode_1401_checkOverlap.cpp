#include <iostream>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = (xCenter<x1 ? x1 : (xCenter>x2 ? x2 : xCenter));
        int y = (yCenter<y1 ? y1 : (yCenter>y2 ? y2 : yCenter));
        return (x-xCenter)*(x-xCenter) + (y-yCenter)*(y-yCenter) <= radius*radius;
    }
};

int main(){
    Solution s;
    int radius = 1, xCenter = 0, yCenter = 0;
    int x1 = 1, y1 = -1, x2 = 3, y2 = 1;
    cout << s.checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2) << endl;
}
