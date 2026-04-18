#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        int x = 0;
        for (int i=s.size()-1; i>=0; i--){
            x = x*10+(s[i]-'0');
        }
        return abs(n-x);
    }
};

int main(){
    Solution s;
    int n = 25;
    cout << s.mirrorDistance(n) << endl;
}
