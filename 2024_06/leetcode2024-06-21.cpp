#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int theTrend(int a, int b){
        if (a > b) return -1;
        if (a < b) return 1;
        return 0;
    }
    int temperatureTrend(vector<int>& tA, vector<int>& tB) {
        int n = tA.size();
        int cur = 0, res = 0;
        for (int i=1; i<n; i++){
            int tmpA = theTrend(tA[i-1], tA[i]);
            int tmpB = theTrend(tB[i-1], tB[i]);
            if (tmpA == tmpB){
                cur++;
            }
            else{
                res = max(res, cur);
                cur = 0;
            }
        }
        return max(res, cur);
    }
};

int main(){
    Solution s;
    vector<int> tA = {21,18,18,18,31};
    vector<int> tB = {34,32,16,16,17};
    cout << s.temperatureTrend(tA, tB) << endl;
}
