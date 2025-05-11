#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for (int i=1; i<n-1; i++){
            if (arr[i-1]%2+arr[i]%2+arr[i+1]%2 == 3){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,2,34,3,4,5,7,23,12};
    cout << s.threeConsecutiveOdds(arr) << endl;
}
