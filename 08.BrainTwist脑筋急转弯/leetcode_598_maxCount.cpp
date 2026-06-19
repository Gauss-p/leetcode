#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mnX=m, mnY=n;
        for (auto& o : ops){
            mnX = min(mnX, o[0]);
            mnY = min(mnY, o[1]);
        }
        return mnX*mnY;
    }
};

int main(){
    Solution s;
    int m=3,n=3;
    vector<vector<int>> ops = {{2,2},{3,3}};
    cout << s.maxCount(m,n,ops) << endl;
}
