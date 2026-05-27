#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> lPos(26, -1), uPos(26, -1);
        for (int i=0; i<n; i++){
            char cur = word[i];
            if ('a' <= cur && cur <= 'z'){
                lPos[cur-'a'] = i;
            }
            else{
                if (uPos[cur-'A'] == -1){
                    uPos[cur-'A'] = i;
                }
            }
        }
        int res = 0;
        for (int i=0; i<26; i++){
            if (lPos[i] >= 0 && uPos[i] >= 0 && lPos[i] < uPos[i]){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string word = "aaAbcBc";
    cout << s.numberOfSpecialChars(word) << endl;
}
