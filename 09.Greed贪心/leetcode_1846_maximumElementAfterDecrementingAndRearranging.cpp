#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int cur = 1;
        for (int i=1; i<arr.size(); i++){
            cur = min(cur+1, arr[i]);
        }
        return cur;
    }
};

int main(){
    Solution s;
    vector<int> arr = {2,2,1,2,1};
    cout << s.maximumElementAfterDecrementingAndRearranging(arr) << endl;
}
