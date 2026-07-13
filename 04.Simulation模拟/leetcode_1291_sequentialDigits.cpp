#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> tot = {1,2,3,4,5,6,7,8,9,
                           12,23,34,45,56,67,78,89,
                           123,234,345,456,567,678,789,
                           1234,2345,3456,4567,5678,6789,
                           12345,23456,34567,45678,56789,
                           123456,234567,345678,456789,
                           1234567,2345678,3456789,
                           12345678,23456789,
                           123456789};
        int il = lower_bound(tot.begin(), tot.end(), low)-tot.begin();
        int ir = upper_bound(tot.begin(), tot.end(), high)-tot.begin();
        vector<int> res = {};
        for (int i=il; i<ir; i++){
            res.push_back(tot[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    int low = 100, high = 300;
    vector<int> res = s.sequentialDigits(low, high);
    for (int i : res) cout << i << " ";
    cout << endl;
}
