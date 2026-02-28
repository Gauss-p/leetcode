#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        prices.push_back(INT_MAX);
        int n = prices.size();
        long long res = 0;
        int last = 0;
        for (int i=0; i<n-1; i++){
            if (prices[i]-1 != prices[i+1]){
                int length = i-last+1;
                res += 1ll*(length+1)*length/2;
                last = i+1;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> prices = {3,2,1,4};
    cout << s.getDescentPeriods(prices) << endl;
}
