#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int res = 0;
        for (int i=0; i<s.size(); i+=2){
            res += (s[i]!=s[i+1]);
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "1001";
    cout << sl.minChanges(s) << endl;
}
