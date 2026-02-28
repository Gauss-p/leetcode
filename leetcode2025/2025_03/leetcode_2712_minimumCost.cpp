#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    long long minimumCost(string s) {
        // 如果s[i]和s[i+1]不同，那么我们必须要翻转s[:i+1]和s[i+1:]其中一个，代价为min(i+1, n-i-1)
        // 但是就算翻转，我们对其他位置数字的不同也不会产生任何影响，所以直接贪心往后计算即可
        int n = s.size();
        long long res = 0;
        for (int i=0; i<n-1; i++){
            if (s[i] != s[i+1]){
                res += min(i+1, n-i-1);
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "0011";
    cout << sl.minimumCost(s) << endl;
}
