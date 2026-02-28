#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size()-1;
        int indx = 0;
        while (indx<n){
            if (bits[indx] == 0){
                indx++;
            }
            else{
                if (indx+1 < n){
                    indx += 2;
                }
                else{
                    break;
                }
            }
        }
        return indx==n;
    }
};

int main(){
    Solution s;
    vector<int> bits = {1,0,0};
    cout << s.isOneBitCharacter(bits) << endl;
}
