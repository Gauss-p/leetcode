#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        s += '.';
        int n = s.size();
        int last = 0;
        vector<int> parts;
        for (int i=1; i<n; i++){
            if (s[i] != s[last]){
                parts.push_back(i-last);
                last = i;
            }
        }

        int res = 0;
        for (int i=0; i<parts.size()-1; i++){
            res += min(parts[i], parts[i+1]);
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "00110011";
    cout << sl.countBinarySubstrings(s) << endl;
}
