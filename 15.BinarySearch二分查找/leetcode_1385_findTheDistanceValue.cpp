#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int res = 0;
        for (int i : arr1){
            int mn = i-d;
            int l = lower_bound(arr2.begin(), arr2.end(), mn)-arr2.begin();
            if (l < arr2.size() && arr2[l]-i <= d){
                continue;
            }
            res++;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr1 = {4,5,8}, arr2 = {10,9,1,8};
    int d = 2;
    cout << s.findTheDistanceValue(arr1, arr2, d) << endl;
}
