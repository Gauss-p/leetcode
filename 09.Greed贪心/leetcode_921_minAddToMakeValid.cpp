#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        unordered_map<int, int> val = {{'(', 1}, {')', -1}};
        int res = 0, cnt = 0;
        for (auto& c : s){
            cnt += val[c];
            if (cnt < 0){
                res++;
                cnt++;
            }
        }
        return res+cnt;
    }
};

int main(){
    Solution sl;
    string s = "())";
    cout << sl.minAddToMakeValid(s) << endl;
}
