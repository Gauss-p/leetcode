#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        vector<int> nums(n);
        for (int i=0; i<n; i++){
            nums[i] = s[i]-'0';
        }
        int res = INT_MIN;
        for (int x=0; x<=4; x++){
            for (int y=0; y<=4; y++){
                if (x == y){
                    continue;
                }
                int l = 0;
                vector<int> left_preSum(5, 0);
                vector<int> right_preSum(5, 0);
                vector<vector<int>> minV(2, vector<int>(2, INT_MAX/2));
                for (int r=1; r<=n; r++){
                    right_preSum[nums[r-1]]++;
                    while (r-l>=k && right_preSum[x]>left_preSum[x] && right_preSum[y]>left_preSum[y]){
                        int p = left_preSum[x]&1, q = left_preSum[y]&1;
                        minV[p][q] = min(minV[p][q], left_preSum[x]-left_preSum[y]);
                        left_preSum[nums[l]]++;
                        l++;
                    }
                    if (r >= k){
                        int rp = right_preSum[x]&1^1, rq = right_preSum[y]&1;
                        res = max(res, right_preSum[x]-right_preSum[y]-minV[rp][rq]);
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "12233";
    int k = 4;
    cout << sl.maxDifference(s, k) << endl;
}
