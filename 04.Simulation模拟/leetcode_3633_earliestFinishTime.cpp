#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int l = landStartTime.size(), w = waterStartTime.size();
        int res = INT_MAX;
        for (int i=0; i<l; i++){
            int st1 = landStartTime[i], d1 = landDuration[i];
            for (int j=0; j<w; j++){
                int st2 = waterStartTime[j], d2 = waterDuration[j];
                res = min(res, st1+d1+max(0, st2-st1-d1)+d2);
                res = min(res, st2+d2+max(0, st1-st2-d2)+d1);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> landStartTime = {2,8}, landDuration = {4,1}, waterStartTime = {6}, waterDuration = {3};
    cout << s.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration) << endl;
}
