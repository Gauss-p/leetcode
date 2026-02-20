#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int res = 0, curMax = neededTime[0], curSum = neededTime[0];
        for (int i=1; i<n; i++){
            if (colors[i-1] != colors[i]){
                res += curSum-curMax;
                curMax = neededTime[i];
                curSum = neededTime[i];
            }
            else{
                curMax = max(curMax, neededTime[i]);
                curSum += neededTime[i];
            }
        }
        return res+(curSum-curMax);
    }
};

int main(){
    Solution s;
    string colors = "abaac";
    vector<int> neededTime = {1,2,3,4,5};
    cout << s.minCost(colors, neededTime) << endl;
}
