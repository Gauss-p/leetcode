#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, cur = 0;
        for (int i : gain){
            cur += i;
            res = max(res, cur);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> gain = {-5,1,5,0,-7};
    cout << s.largestAltitude(gain) << endl;
}
