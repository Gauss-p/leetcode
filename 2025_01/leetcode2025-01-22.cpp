#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size()/3;
        int res = 0;
        for (int i=n; i<3*n; i+=2){
            res += piles[i];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> piles = {2,4,1,2,7,8};
    cout << s.maxCoins(piles) << endl;
}
