#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int maxPos = startPos+k;
        vector<int> preSum(maxPos+2, 0);
        int i=0, j=0;
        while (i<=maxPos){
            if (j<fruits.size() && i == fruits[j][0]){
                preSum[i+1] = preSum[i]+fruits[j][1];
                j++;
            }
            else{
                preSum[i+1] = preSum[i];
            }
            i++;
        }
        int res = 0;
        for (int rightStep=0; rightStep<=k; rightStep++){
            int l = min(startPos, max(0, startPos-(k-2*rightStep))), r = startPos+rightStep;
            res = max(res, preSum[r+1]-preSum[l]);
        }
        for (int leftStep=0; leftStep<=k; leftStep++){
            int l = startPos-leftStep, r = startPos+(k-2*leftStep);
            if (l<0){
                continue;
            }
            res = max(res, preSum[r+1]-preSum[l]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> fruits = {{2,8},{6,3},{8,6}};
    int startPos = 5, k = 4;
    cout << s.maxTotalFruits(fruits, startPos, k) << endl;
}
