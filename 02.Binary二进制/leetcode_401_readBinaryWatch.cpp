#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for (int h=0; h<12; h++){
            int b1 = __builtin_popcount(h);
            if (b1 > turnedOn){
                continue;
            }
            for (int m=0; m<60; m++){
                int b2 = __builtin_popcount(m);
                if (b1+b2 == turnedOn){
                    string cur = to_string(h)+":";
                    if (m<10){
                        cur += "0"+to_string(m);
                    }
                    else{
                        cur += to_string(m);
                    }
                    res.push_back(cur);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int turnedOn = 1;
    vector<string> res = s.readBinaryWatch(turnedOn);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
