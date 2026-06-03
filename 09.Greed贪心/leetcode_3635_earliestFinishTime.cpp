#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int l = landStartTime.size(), w = waterStartTime.size();
        int minLand = INT_MAX, minWater = INT_MAX;
        for (int i=0; i<l; i++){
            minLand = min(minLand, landStartTime[i]+landDuration[i]);
        }
        for (int i=0; i<w; i++){
            minWater = min(minWater, waterStartTime[i]+waterDuration[i]);
        }
        int res = INT_MAX;
        for (int i=0; i<w; i++){
            res = min(res, max(minLand, waterStartTime[i])+waterDuration[i]);
        }
        for (int i=0; i<l; i++){
            res = min(res, max(minWater, landStartTime[i])+landDuration[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> landStartTime = {2,8}, landDuration = {4,1}, waterStartTime = {6}, waterDuration = {3};
    cout << s.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration) << endl;
}
