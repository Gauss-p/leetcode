#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> mp;
        for (int i=lowLimit; i<=highLimit; i++){
            int tmp = i, sm = 0;
            while (tmp){
                sm += tmp%10;
                tmp /= 10;
            }
            mp[sm]++;
        }
        int res = 0;
        for (auto& kv : mp) res = max(res, kv.second);
        return res;
    }
};

int main(){
    Solution s;
    int lowLimit=1, highLimit=10;
    cout << s.countBalls(lowLimit, highLimit) << endl;
}
