#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool is_zero_in(int a){
        while (a){
            if (a%10 == 0){
                return true;
            }
            a /= 10;
        }
        return false;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i=1; i<=n/2; i++){
            int j = n-i;
            if (!is_zero_in(i) && !is_zero_in(j)){
                return {i,j};
            }
        }
        return {};
    }
};

int main(){
    Solution s;
    int n = 2;
    vector<int> res = s.getNoZeroIntegers(n);
    cout << res[0] << " " << res[1] << endl;
}
