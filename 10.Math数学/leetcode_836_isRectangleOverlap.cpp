#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int hor = min(rec1[2], rec2[2])-max(rec1[0], rec2[0]);
        int ver = min(rec1[3], rec2[3])-max(rec1[1], rec2[1]);
        return hor>0 && ver>0;
    }
};

int main(){
    Solution s;
    vector<int> rec1 = {0,0,1,1}, rec2 = {2,2,3,3};
    cout << s.isRectangleOverlap(rec1, rec2) << endl;
}
