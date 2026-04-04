#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int mn0 = min(startPos[0], homePos[0]), mn1 = min(startPos[1], homePos[1]);
        int mx0 = max(startPos[0], homePos[0]), mx1 = max(startPos[1], homePos[1]);
        int res = 0;
        for (int i=mn0; i<=mx0; i++){
            res += rowCosts[i];
        }
        for (int i=mn1; i<=mx1; i++){
            res += colCosts[i];
        }
        return res-rowCosts[startPos[0]]-colCosts[startPos[1]];
    }
};

int main(){
    Solution s;
    vector<int> startPos = {1,0}, homePos = {2,3}, rowCosts = {5,4,3}, colCosts = {8,2,6,7};
    cout << s.minCost(startPos, homePos, rowCosts, colCosts) << endl;
}
