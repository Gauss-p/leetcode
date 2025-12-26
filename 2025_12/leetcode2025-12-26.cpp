#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> preSum(n+1, 0), sufSum(n+1, 0);
        for (int i=0; i<n; i++){
            preSum[i+1] = preSum[i]+(customers[i]=='N');
            sufSum[n-i-1] = sufSum[n-i]+(customers[n-i-1]=='Y');
        }

        int cost = INT_MAX, res = 0;
        for (int i=0; i<n+1; i++){
            if (preSum[i]+sufSum[i] < cost){
                cost = preSum[i]+sufSum[i];
                res = i;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string customers = "YYNY";
    cout << s.bestClosingTime(customers) << endl;
}
