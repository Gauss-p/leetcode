#include <iostream>
using namespace std;

class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        long long mn = min(need1, need2), mx = max(need1, need2);
        return min(min(need1*cost1+need2*cost2, mx*costBoth), mn*costBoth+(need1-mn)*cost1+(need2-mn)*cost2);
    }
};

int main(){
    Solution s;
    int cost1 = 3;
    int cost2 = 2;
    int costBoth = 1;
    int need1 = 3;
    int need2 = 2;
    cout << s.minimumCost(cost1, cost2, costBoth, need1, need2) << endl;
}
