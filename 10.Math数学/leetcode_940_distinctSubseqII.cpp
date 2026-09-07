#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        int modNum = 1e9+7;
        vector<int> cnt(26, 0);
        long long tot = 0;
        for (int i=0; i<s.size(); i++){
            int cur = cnt[s[i]-'a'];
            cnt[s[i]-'a'] = (tot+1)%modNum;
            tot = (tot-cur+cnt[s[i]-'a']+modNum)%modNum;
        }
        return tot;
    }
};

int main(){
    Solution sl;
    string s = "aaa";
    cout << sl.distinctSubseqII(s) << endl;
}
