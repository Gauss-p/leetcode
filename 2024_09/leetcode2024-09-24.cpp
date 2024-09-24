#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long res = 0;
        long long cnt0 = 0, cnt1 = 0;
        for (char i : text){
            if (i == pattern[1]){
                res += cnt0;
                cnt1++;
            }
            if (i == pattern[0]){
                cnt0++;
            }
        }
        return res+max(cnt0, cnt1);
    }
};

int main(){
    Solution s;
    string text = "aabb";
    string pattern = "ab";
    cout << s.maximumSubsequenceCount(text, pattern) << endl;
}
