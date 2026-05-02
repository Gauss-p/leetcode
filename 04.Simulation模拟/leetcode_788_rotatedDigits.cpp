#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int rotatedDigits(int n) {
        unordered_map<int, int> matches = {{0,0},{1,1},{8,8},{2,5},{5,2},{6,9},{9,6}};
        int res = 0;
        for (int i=1; i<=n; i++){
            string cur = to_string(i);
            string rotated;
            bool flag = true;
            for (auto& c : cur){
                if (c == '3' || c == '4' || c == '7'){
                    flag = false;
                    break;
                }
                rotated += to_string(matches[c-'0']);
            }
            if (flag){
                res += (rotated != cur);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 10;
    cout << s.rotatedDigits(n) << endl;
}
