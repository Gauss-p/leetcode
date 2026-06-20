#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& R) {
        sort(R.begin(), R.end());
        R.insert(R.begin(), {1,0});
        if (R.back()[0] != n){
            R.push_back({n, n-1});
        }

        int m = R.size();
        for (int i=1; i<m; i++){
            R[i][1] = min(R[i][1], R[i-1][1]+(R[i][0]-R[i-1][0]));
        }
        for (int i=m-2; i>=1; i--){
            R[i][1] = min(R[i][1], R[i+1][1]+(R[i+1][0]-R[i][0]));
        }

        int res = 0;
        for (int i=0; i<m-1; i++){
            int best = (R[i+1][0]-R[i][0]+R[i][1]+R[i+1][1])/2;
            res = max(res, best);
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 5;
    vector<vector<int>> R = {{2,1},{4,1}};
    cout << s.maxBuilding(n, R) << endl;
}
