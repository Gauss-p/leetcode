#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int res = 0, n = text.size();
        unordered_map<char, int> broken;
        for (auto& c : brokenLetters) broken[c] = 1;
        int cnt = 0;
        for (int i=0; i<n; i++){
            cnt += broken[text[i]];
            if (text[i] == ' ' || i == n-1){
                if (cnt == 0){
                    res++;
                }
                cnt = 0;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string text = "hello world", brokenLetters = "ad";
    cout << s.canBeTypedWords(text, brokenLetters) << endl;
}
