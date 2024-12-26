#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.size();
        for (int i=0; i<n-1; i++){
            string tmp = s.substr(i+1, 1) + s.substr(i, 1);
            if (s.find(tmp) != string::npos){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sl;
    string s = "leetcode";
    cout << sl.isSubstringPresent(s) << endl;
}
