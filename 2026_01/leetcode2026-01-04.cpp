#include <iostream>
#include <vector>
using namespace std;

const int maxNum = 100001;
vector<int> factorCnt(maxNum, 0);
vector<int> factorSum(maxNum, 0);

int init = []{
    for (int i=1; i<maxNum; i++){
        for (int j=i; j<maxNum; j+=i){
            factorCnt[j] += 1;
            factorSum[j] += i;
        }
    }
    return 0;
}();

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (int& i : nums){
            if (factorCnt[i] == 4){
                res += factorSum[i];
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {21,4,7};
    cout << s.sumFourDivisors(nums) << endl;
}
