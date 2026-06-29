#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for (auto& s : patterns){
            for (int i=0; i<word.size(); i++){
                if (word.substr(i, s.size()) == s){
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> patterns = {"a","abc","bc","d"};
    string word = "abc";
    cout << s.numOfStrings(patterns, word) << endl;
}
