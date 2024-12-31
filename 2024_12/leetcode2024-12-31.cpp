#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        int i=0, j=0;
        int vert = 1, hori = 1;
        long long res = 0;
        while (i < m-1 && j < n-1){
            if (horizontalCut[i] > verticalCut[j]){
                res += 1ll*horizontalCut[i]*vert;
                hori++;
                i++;
            }
            else{
                res += 1ll*verticalCut[j]*hori;
                vert++;
                j++;
            }
        }
        while (i < m-1){
            res += 1ll*horizontalCut[i]*vert;
            i++;
        }
        while (j < n-1){
            res += 1ll*verticalCut[j]*hori;
            j++;
        }
        return res;
    }
};

int main(){
    Solution s;
    int m = 3, n = 2;
    vector<int> horizontalCut = {1,3}, verticalCut = {5};
    cout << s.minimumCost(m, n, horizontalCut, verticalCut) << endl;
}
