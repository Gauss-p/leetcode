#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    char myLower(char c){
        if ('A' <= c && c <= 'Z'){
            return ('a'+(c-'A'));
        }
        return c;
    }
public:
    int countKeyChanges(string s) {
        int n = s.size();
        int res = 0;
        for (int i=1; i<n; i++){
            if (myLower(s[i]) != myLower(s[i-1])){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "aAbBcC";
    cout << sl.countKeyChanges(s) << endl;
}
