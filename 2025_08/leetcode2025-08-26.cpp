#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int diagonal = 0, area = 0;
        for (auto& d : dimensions){
            int a = d[0], b = d[1];
            int cur = a*a+b*b;
            if (cur > diagonal){
                diagonal = cur;
                area = a*b;
            }
            else if (cur == diagonal){
                area = max(area, a*b);
            }
        }
        return area;
    }
};

int main(){
    Solution s;
    vector<vector<int>> dimensions = {{9,3},{8,6}};
    cout << s.areaOfMaxDiagonal(dimensions) << endl;
}
