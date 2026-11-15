#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int odd = 0, even = 1, preSum = 0, modNum = 1e9+7, res = 0;
        for (int i : arr){
            preSum += i;
            if (preSum & 1){
                res = (res+even)%modNum;
                odd++;
            }
            else{
                res = (res+odd)%modNum;
                even++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1, 3, 5};
    cout << s.numOfSubarrays(arr) << endl;
}
