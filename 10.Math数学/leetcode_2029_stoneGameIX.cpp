#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int n;
    bool check(int a, int b, int c){
        if (b < 1){
            return false;
        }
        b -= 1;
        int tot = 1+min(b,c)*2+a;
        if (b > c){
            tot++;
        }
        return tot<n && tot%2 == 1;
    }
public:
    bool stoneGameIX(vector<int>& stones) {
        n = stones.size();
        vector<int> cnt(3, 0);
        for (int i : stones) cnt[i%3]++;
        int a = cnt[0], b = cnt[1], c = cnt[2];
        return check(a, b, c) | check(a, c, b);
    }
};

int main(){
    Solution s;
    vector<int> stones = {2,1};
    cout << s.stoneGameIX(stones) << endl;
}
