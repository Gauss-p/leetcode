#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnt;
        for (int i : answers){
            cnt[i]++;
        }
        int res = 0;
        for (auto&kv : cnt){
            res += ((kv.second+kv.first)/(kv.first+1))*(kv.first+1);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> answers = {1,1,2};
    cout << s.numRabbits(answers) << endl;
}
