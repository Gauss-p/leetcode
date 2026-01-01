#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int add = 1;
        for (int i=n-1; i>=0; i--){
            if (add == 0){
                break;
            }
            if (digits[i] <= 8){
                digits[i]++;
                add = 0;
            }
            else{
                digits[i] = 0;
            }
        }
        if (add == 1){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main(){
    Solution s;
    vector<int> digits = {1,2,3};
    vector<int> res = s.plusOne(digits);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
