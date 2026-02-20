#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (int i=0; i<n; i++){
            mp[s[i]] = i;
        }
        int res = 0;
        for (int i=0; i<n; i++){
            res += abs(i-mp[t[i]]);
        }
        return res;
    }
};

int main(){
    Solution so;
    string s = "abc", t = "cab";
    cout << so.findPermutationDifference(s, t) << endl;
}
