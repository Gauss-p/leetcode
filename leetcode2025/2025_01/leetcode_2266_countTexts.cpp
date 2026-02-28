#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    int modNum = 1e9+7;
    
public:
    int countTexts(string pressedKeys) {
        vector<long long> f = {1,1,2,4};
        vector<long long> g = {1,1,2,4};
        for (int i=4; i<=1e5; i++){
            f.push_back((f[i-1]+f[i-2]+f[i-3])%modNum);
            g.push_back((g[i-1]+g[i-2]+g[i-3]+g[i-4])%modNum);
        }
        pressedKeys += '%';
        int length = 1;
        int n = pressedKeys.size();
        long long res = 1;
        for (int i=1; i<n; i++){
            if (pressedKeys[i] == pressedKeys[i-1]){
                length++;
                continue;
            }
            if (pressedKeys[i-1] != '7' && pressedKeys[i-1] != '9'){
                res = (res*f[length])%modNum;
            }
            else{
                res = (res*g[length])%modNum;
            }
            length = 1;
        }
        return res;
    }
};

int main(){
    Solution s;
    string pressedKeys = "22233";
    cout << s.countTexts(pressedKeys) << endl;
}
