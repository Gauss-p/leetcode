#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int r = 0;
        unordered_map<int, int> cnt;
        int res = 0;
        for (int l=0; l<n; l++){
            while (r<n && cnt[s[r]] <= 1){
                cnt[s[r]]++;
                r++;
            }
            res = max(res, r-l);
            cnt[s[l]]--;
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "bcbbbacb";
    cout << sl.maximumLengthSubstring(s) << endl;
}
