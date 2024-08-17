#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> dic;
        int n = word.size();
        for (int i=0; i<n; i+=k){
            dic[word.substr(i, k)]++;
        }
        int res = 0;
        for (auto &kv : dic){
            res = max(res, kv.second);
        }
        return n/k-res;
    }
};

int main(){
    Solution s;
    string word = "leetcodeleet";
    int k = 4;
    cout << s.minimumOperationsToMakeKPeriodic(word, k) << endl;
}
