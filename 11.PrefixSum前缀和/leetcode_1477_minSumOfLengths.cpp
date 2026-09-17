#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, int> cnt;
        vector<int> preSum(n+1, 0);
        cnt[0] = 0;
        for (int i=0; i<n; i++){
            preSum[i+1] = preSum[i]+arr[i];
            cnt[preSum[i+1]] = i+1;
        }

        int before = INT_MAX/2, res = INT_MAX/2;
        for (int i=0; i<n; i++){
            int length = INT_MAX/2;
            if (cnt.count(preSum[i]+target)){
                length = cnt[preSum[i]+target]-i;
            }
            res = min(res, before+length);
            if (cnt.count(preSum[i+1]-target)){
                before = min(before, i-cnt[preSum[i+1]-target]+1);
            }
        }
        return res==INT_MAX/2 ? -1 : res;
    }
};

int main(){
    Solution s;
    vector<int> arr = {3,2,2,4,3};
    int target = 3;
    cout << s.minSumOfLengths(arr, target) << endl;
}
