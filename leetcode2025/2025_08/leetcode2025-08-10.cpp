#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxNum = 1000000000;
vector<int> pow2;

auto init = [](){
    pow2 = {1};
    while (pow2.back() < maxNum){
        pow2.push_back(pow2.back()<<1);
    }
    return 0;
}();

class Solution {
private:
    bool is_equal(int a, int b){
        unordered_map<int, int> cntA, cntB;
        while (a){
            cntA[a%10]++;
            a /= 10;
        }
        while (b){
            cntB[b%10]++;
            b /= 10;
        }
        return cntA == cntB;
    }
public:
    bool reorderedPowerOf2(int n) {
        for (int x : pow2){
            if (is_equal(n, x)){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    int n = 61;
    cout << s.reorderedPowerOf2(n) << endl;
}
