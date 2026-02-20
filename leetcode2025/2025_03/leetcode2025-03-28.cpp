#include <iostream>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
    int minimizedStringLength(string s) {
        return set<char>(s.begin(), s.end()).size();
    }
};

int main(){
    Solution sl;
    string s = "aaabc";
    cout << sl.minimizedStringLength(s) << endl;
}
