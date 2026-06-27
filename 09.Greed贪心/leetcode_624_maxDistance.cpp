#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn = INT_MAX/2, mx = -INT_MAX/2, res = 0;
        for (auto& a : arrays){
            res = max(res, max(mx-a[0], a[a.size()-1]-mn));
            mn = min(mn, a[0]);
            mx = max(mx, a[a.size()-1]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> arrays = {{1,2,3},{4,5},{1,2,3}};
    cout << s.maxDistance(arrays) << endl;
}
