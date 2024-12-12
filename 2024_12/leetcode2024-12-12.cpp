#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        vector<int> totVal;
        int m = values.size(), n = values[0].size();
        for (auto i : values){
            totVal.insert(totVal.end(), i.begin(), i.end());
        }
        sort(totVal.begin(), totVal.end());
        long long res = 0;
        for (int i=0; i<m*n; i++){
            res += 1ll*(i+1)*totVal[i];
        }
        return res;
        // long long res = 0, day = 1;
        // int m = values.size(), n = values[0].size();
        // vector<int> indx(m, -1);
        // for (int i=0; i<n*m; i++){
        //     int tmpIndx = 0, v = INT_MAX;
        //     for (int j=0; j<m; j++){
        //         if ((indx[j] != (-n-1)) && (values[j][indx[j]+n] < v)){
        //             v = values[j][indx[j]+n];
        //             tmpIndx = j;
        //         }
        //     }
        //     res += values[tmpIndx][indx[tmpIndx]+n]*day;
        //     day++;
        //     indx[tmpIndx]--;
        // }
        // return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> values = {{8,5,2},{6,4,1},{9,7,3}};
    cout << s.maxSpending(values) << endl;
}
