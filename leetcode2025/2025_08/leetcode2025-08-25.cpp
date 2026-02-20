#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int op = -1;
        vector<int> res;
        for (int curSum=0; curSum<m+n-1; curSum++){
            int low = max(0, curSum-n+1);
            // curSum-low<n --> curSum-n<low
            int high = min(m-1, curSum);
            if (op==-1){
                swap(low, high);
            }
            for (int i=op*low; i<=op*high; i++){
                int j = curSum-abs(i);
                res.push_back(mat[abs(i)][j]);
            }
            op *= -1;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = s.findDiagonalOrder(mat);
    for (int i : res){
	cout << i << " ";
    }
    cout << endl;
}
