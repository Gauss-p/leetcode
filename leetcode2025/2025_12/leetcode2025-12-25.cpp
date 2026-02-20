#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), [](auto& a, auto& b){
            return a>b;
        });
        long long res = 0;
        for (int i=0; i<k; i++){
            if (happiness[i] <= i) break;
            res += happiness[i]-i;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> happiness = {1,2,3};
    int k = 2;
    cout << s.maximumHappinessSum(happiness, k) << endl;
}
