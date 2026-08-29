#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        int n = flowers.size();
        long long leftFlowers = newFlowers;
        for (int i=0; i<n; i++){
            flowers[i] = min(flowers[i], target);
            leftFlowers -= (target-flowers[i]);
        }

        if (leftFlowers == newFlowers){
            return 1ll*n*full;
        }
        if (leftFlowers >= 0){
            return max(1ll*(target-1)*partial+1ll*(n-1)*full, 1ll*n*full);
        }

        sort(flowers.begin(), flowers.end());
        long long res=0, j=0, preSum=0;
        for (int i=1; i<=n; i++){
            leftFlowers += (target-flowers[i-1]);
            if (leftFlowers < 0){
                continue;
            }

            while (j<i && j*flowers[j]-preSum<=leftFlowers){
                preSum += flowers[j];
                j++;
            }

            int avg = (leftFlowers+preSum)/j;
            long long tmpBeauty = 1ll*avg*partial+1ll*(n-i)*full;
            res = max(res, tmpBeauty);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> flowers = {1,3,1,1};
    int newFlowers=7, target=6, full=12, partial=1;
    cout << s.maximumBeauty(flowers, newFlowers, target, full, partial) << endl;
}
