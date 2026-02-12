#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;
        for (int i=0; i<n; i++){
            vector<int> cnt(26, 0);
            unordered_map<int, int> same;
            int curLength = 0;
            for (int j=i; j<n; j++){
                int indx = s[j]-'a';
                if (same[cnt[indx]]){
                    same[cnt[indx]] -= 1;
                    if (same[cnt[indx]] == 0){
                        curLength -= 1;
                    }
                }
                cnt[indx]++;
                if (same[cnt[indx]] == 0){
                    curLength += 1;
                }
                same[cnt[indx]]++;
                
                if (curLength==1){
                    res = max(res, j-i+1);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "abbac";
    cout << sl.longestBalanced(s) << endl;
}
