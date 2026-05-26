#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> cnt;
        for (auto& c : word) cnt[c]++;
        int res = 0;
        for (int i=0; i<26; i++){
            if (cnt['a'+i] && cnt['A'+i]){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string word = "aaAbcBC";
    cout << s.numberOfSpecialChars(word) << endl;
}
