#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0;
        unordered_map<char, int> cnt;
        int res = 0;
        for (int r=0; r<n; r++){
            cnt[s[r]]++;
            while (cnt['a'] >= 1 && cnt['b'] >= 1 && cnt['c'] >= 1){
                cnt[s[l]]--;
                l++;
            }
            res += l;
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "abcabc";
    cout << sl.numberOfSubstrings(s) << endl;
}
