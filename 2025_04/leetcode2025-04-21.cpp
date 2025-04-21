#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mx = 0, mn = 0;
        long long tmp = 0;
        for (int& i : differences){
            tmp += i;
            mx = max(mx, tmp);
            mn = min(mn, tmp);
        }
        return max(0ll, upper-(mx+(lower-mn))+1);
    }
};

int main(){
    Solution s;
    vector<int> differences = {1,-3,4};
    int lower = 1, upper = 6;
    cout << s.numberOfArrays(differences, lower, upper) << endl;
}
