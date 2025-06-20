#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        unordered_map<char, int> cnt;
        int res = 0;
        for (int i=0; i<n; i++){
            cnt[s[i]]++;
            int x = abs(cnt['E']-cnt['W']);
            int y = abs(cnt['N']-cnt['S']);
            int canAdd = 2*min(k, min(cnt['E'], cnt['W'])+min(cnt['N'], cnt['S']));
            res = max(res, x+y+canAdd);
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "NWSE";
    int k = 1;
    cout << sl.maxDistance(s,k) << endl;
}
