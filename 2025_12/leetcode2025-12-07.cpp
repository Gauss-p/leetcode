#include <iostream>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        return (high-low+1)/2 + ((low&1==1) && (high&1==1));
    }
};

int main(){
    Solution s;
    int low = 3, high = 7;
    cout << s.countOdds(low, high) << endl;
}
