#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int allXor = 0;
        for (int i : derived){
            allXor ^= i;
        }
        for (int i : derived){
            if (i != allXor^i){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> derived = {1,1,0};
    cout << s.doesValidArrayExist(derived) << endl;
}
