#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> cnt;
        for (auto& c : moves){
            cnt[c]++;
        }
        return cnt['R']==cnt['L'] && cnt['U']==cnt['D'];
    }
};

int main(){
    Solution s;
    string moves = "UD";
    cout << s.judgeCircle(moves) << endl;
}
