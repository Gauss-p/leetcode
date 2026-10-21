#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        string origin = s;
        sort(s.begin(), s.end());
        if (s == origin){
            return 0;
        }
        if (s.size() == 2){
            return -1;
        }

        int n = s.size();
        int mn = s[0], mx = s[n-1];
        if (origin[0] == mn || origin[n-1] == mx){
            return 1;
        }
        if (origin[0] == mx && origin[n-1] == mn){
            if (s[1] != mn && s[n-2] != mx){
                return 3;
            }
        }
        return 2;
    }
};

int main(){
    Solution sl;
    string s = "dog";
    cout << sl.minOperations(s) << endl;
}
