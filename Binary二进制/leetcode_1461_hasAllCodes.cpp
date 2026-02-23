#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int cur = 0;
        int maxNum = 1<<k;
        vector<int> totNums(maxNum, 0);
        for (int i=0; i<n; i++){
            cur = cur<<1 | (s[i]-'0');
            if (i < k-1){
                continue;
            }
            totNums[cur] = 1;
            cur ^= (s[i-k+1]-'0') << (k-1);
        }

        for (int i : totNums){
            if (i == 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sl;
    string s = "00110110";
    int k = 2;
    cout << sl.hasAllCodes(s, k) << endl;
}
