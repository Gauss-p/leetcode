#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long cnt = 0, neg = INT_MIN, res = 0;
        for (auto& i : matrix){
            for (auto& j : i){
                if (j < 0){
                    cnt++;
                }
                res += abs(j);
                neg = max(neg, -1ll*abs(j));
            }
        }
        return cnt%2==0 ? res : res+2*neg;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,-1},{-1,1}};
    cout << s.maxMatrixSum(matrix) << endl;
}
