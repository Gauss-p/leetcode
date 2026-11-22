#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int a = -1, b = -1;
        for (int i=0; i<n; i++){
            if (s[i]=='b' && b==-1){
                b = i;
            }
            if (s[i] == 'a'){
                a = i;
            }
        }
        return (a!=-1 && b!=-1) ? a<b : true;
    }
};

int main(){
    Solution sl;
    string s = "aaabbb";
    cout << sl.checkString(s) << endl;
}
