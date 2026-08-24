#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        int tot = 0;
        for (int i : stones) tot += i;
        int mx = tot;
        for (int i=n-2; i>=1; i--){
            tot -= stones[i+1];
            mx = max(tot-mx, mx);
        }
        return mx;
    }
};

int main(){
    Solution s;
    vector<int> stones = {-1,2,-3,4,-5};
    cout << s.stoneGameVIII(stones) << endl;
}
