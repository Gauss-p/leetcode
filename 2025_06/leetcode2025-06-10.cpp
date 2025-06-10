#include <iostream>
#include <string>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> cnt;
        for (auto c : s){
            cnt[c]++;
        }
        int mx = 0, mn = INT_MAX;
        for (auto& kv : cnt){
            if (kv.second & 1){
                mx = max(mx, kv.second);
            }
            else{
                mn = min(mn, kv.second);
            }
        }
        return mx-mn;
    }
};

int main(){
    Solution sl;
    string s = "aaaaabbc";
    cout << sl.maxDifference(s) << endl;
}
