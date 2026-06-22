#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> origin = {{'b',1},{'a',1},{'l',2},{'o',2},{'n',1}};
        unordered_map<char, int> cnt;
        for (auto& c : text){
            cnt[c]++;
        }
        int res = 1e9;
        for (auto& kv : origin){
            res = min(res, cnt[kv.first]/kv.second);
        }
        return res;
    }
};

int main(){
    Solution s;
    string text = "nlaebolko";
    cout << s.maxNumberOfBalloons(text) << endl;
}
