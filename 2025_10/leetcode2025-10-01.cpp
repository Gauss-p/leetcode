#include <iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int left = numBottles;
        while (left >= numExchange){
            res += (left/numExchange);
            left = left%numExchange+left/numExchange;
        }
        return res;
    }
};

int main(){
    Solution s;
    int numBottles = 9, numExchange = 3;
    cout << s.numWaterBottles(numBottles, numExchange) << endl;
}
