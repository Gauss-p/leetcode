#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](auto& a, auto& b){
            int na = __builtin_popcount(a), nb = __builtin_popcount(b);
            return na<nb || (na==nb && a<b);
        });
        return arr;
    }
};

int main(){
    Solution s;
    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    vector<int> res = s.sortByBits(arr);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
