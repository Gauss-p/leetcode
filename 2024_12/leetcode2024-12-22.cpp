#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int getVal(int x){
        int cnt = 0;
        while (x>1){
            if (x&1){
                x = x*3+1;
            }
            else{
                x /= 2;
            }
            cnt += 1;
        }
        return cnt;
    }
public:
    int getKth(int lo, int hi, int k) {
        vector<vector<int>> vals;
        for (int i=lo; i<=hi; i++){
            vals.push_back({getVal(i), i});
        }
        sort(vals.begin(), vals.end());
        return vals[k-1][1];
    }
};

int main(){
    int lo = 12, hi = 15, k = 2;
    Solution s;
    cout << s.getKth(lo, hi, k) << endl;
}
