#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> rows;
int init=[](){
    rows = {{1}};
    for (int i=1; i<30; i++){
        vector<int> cur = {1};
        for (int j=0; j<rows[i-1].size()-1; j++){
            cur.push_back(rows[i-1][j]+rows[i-1][j+1]);
        }
        cur.push_back(1);
        rows.push_back(cur);
    }
    return 0;
}();

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        return vector<vector<int>>(rows.begin(), rows.begin()+numRows);
    }
};

int main(){
    Solution s;
    int numRows = 5;
    vector<vector<int>> res = s.generate(numRows);
    for (auto i : res){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
