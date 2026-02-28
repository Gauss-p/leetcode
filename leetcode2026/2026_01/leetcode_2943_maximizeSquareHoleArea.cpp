#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
private:
    int maxCountinue(vector<int>& v){
        v.push_back(INT_MAX);
        int length = v.size();
        int res = 0;
        int last = 0;
        for (int i=1; i<length; i++){
            if (v[i]-v[i-1] != 1){
                res = max(res, i-last);
                last = i;
            }
        }
        return res+1;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int edge = min(maxCountinue(hBars), maxCountinue(vBars));
        return edge*edge;
    }
};

int main(){
    Solution s;
    int n = 2, m = 1;
    vector<int> hBars = {2,3}, vBars = {2};
    cout << s.maximizeSquareHoleArea(n, m, hBars, vBars) << endl;
}
