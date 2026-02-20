#include <iostream>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles, left = numBottles;
        while (left >= numExchange){
            res += 1;
            left = left - numExchange + 1;
            numExchange += 1;
        }
        return res;
    }
};

int main(){
    Solution s;
    int numBottles = 13, numExchange = 6;
    cout << s.maxBottlesDrunk(numBottles, numExchange) << endl;
}
