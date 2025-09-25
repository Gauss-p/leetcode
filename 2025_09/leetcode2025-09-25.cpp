#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i=1; i<n; i++){
            for (int j=0; j<=i; j++){
                int cur = INT_MAX;
                if (j>0){
                    cur = min(cur, triangle[i-1][j-1]);
                }
                if (j<i){
                    cur = min(cur, triangle[i-1][j]);
                }
                triangle[i][j] += cur;
            }
        }
        return *min_element(triangle[n-1].begin(), triangle[n-1].end());
    }
};

int main(){
    Solution s;
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << s.minimumTotal(triangle) << endl;
}
