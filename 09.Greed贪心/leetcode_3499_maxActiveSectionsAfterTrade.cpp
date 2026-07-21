#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s += '2';
        int n = s.size();
        int last = 0;
        int cnt = 0;
        vector<int> pos, length;
        for (int i=1; i<n; i++){
            cnt += (s[i-1]=='1');
            if (s[i] != s[i-1]){
                pos.push_back(last);
                length.push_back(i-last);
                last = i;
            }
        }

        int res = cnt;
        int m = pos.size();
        for (int i=1; i<m-1; i++){
            if (s[pos[i-1]]=='0' && s[pos[i]]=='1' && s[pos[i+1]]=='0'){
                res = max(res, cnt+length[i-1]+length[i+1]);
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "0100";
    cout << sl.maxActiveSectionsAfterTrade(s) << endl;
}
