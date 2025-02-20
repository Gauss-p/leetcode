#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> res(2, 0);
        int indx = 0;
        while (n){
            if (n&1){
                if (indx&1){
                    res[1]++;
                }
                else{
                    res[0]++;
                }
            }
            indx++;
            n >>= 1;
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 50;
    cout << s.evenOddBit(n)[0] << " " << s.evenOddBit(n)[1] << endl;
}
