#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int d0 = arr[0], d1 = 0, n = arr.size(), res = arr[0];
        for (int i=1; i<n; i++){
            d1 = max(d1+arr[i], d0);
            d0 = max(d0, 0)+arr[i];
            res = max(res, d1);
            res = max(res, d0);
        }
        return res;
    }
};

int main(){
    unordered_map<pair<int, int>, int> mp;
    mp[make_pair(1,2)] = 1;
    cout << mp[make_pair(1,2)] << endl;
    // vector<int> arr = {1, -2, 0, 3};
    // Solution s;
    // cout << s.maximumSum(arr) << endl;
}
