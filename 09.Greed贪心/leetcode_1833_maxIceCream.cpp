#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int mx = *max_element(costs.begin(), costs.end());
        vector<int> tot(mx+1, 0);
        for (int i : costs){
            tot[i]++;
        }

        int res = 0;
        for (int i=1; i<=mx; i++){
            if (coins < i){
                break;
            }
            int cnt = min(coins/i, tot[i]);
            coins -= i*cnt;
            res += cnt;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> costs = {1,3,2,4,1};
    int coins = 7;
    cout << s.maxIceCream(costs, coins) << endl;
}
