#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long ans = 0, tot = 0;
        for (auto& t : transactions){
            long long cost = t[0], cashback = t[1];
            if (cost>cashback){
                tot += cost-cashback;
                ans = max(ans, cashback);
            }
            else{
                ans = max(ans, cost);
            }
        }
        return ans+tot;
    }
};

int main(){
    Solution s;
    vector<vector<int>> transactions = {{2,1},{5,0},{4,2}};
    cout << s.minimumMoney(transactions) << endl;
}
