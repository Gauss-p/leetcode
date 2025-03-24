#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int res = 0;
        for (auto& i : words) if (s.substr(0,i.size()) == i) res++;
        return res;
    }
};

int main(){
    Solution sl;
    vector<string> words = {"a","b","c","ab","bc","abc"};
    string s = "abc";
    cout << sl.countPrefixes(words, s) << endl;
}
