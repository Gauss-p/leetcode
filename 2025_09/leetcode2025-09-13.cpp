#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        int res1 = 0, res2 = 0;
        unordered_map<char, int> cnt;
        for (auto& c : s){
            cnt[c]++;
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                res1 = max(res1, cnt[c]);
            }
            else{
                res2 = max(res2, cnt[c]);
            }
        }
        return res1+res2;
    }
};

int main(){
    Solution sl;
    string s = "successes";
    cout << sl.maxFreqSum(s) << endl;
}
