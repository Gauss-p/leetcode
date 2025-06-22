#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> res;
        for (int i=0; i<n; i+=k){
            res.push_back(s.substr(i, min(k, n-i))+string(k-min(k, n-i), fill));
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "abcdefghij";
    int k = 3;
    char fill = 'x';
    vector<string> res = sl.divideString(s, k, fill);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
}
