#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();
        unordered_map<char, int> cnt;
        for (auto c : word){
            cnt[c]++;
        }
        int res = INT_MAX;
        for (auto&kv1 : cnt){
            int cur_res = 0;
            for (auto&kv2 : cnt){
                if (kv2.second > kv1.second+k){
                    cur_res += (kv2.second-(kv1.second+k));
                }
                else if (kv2.second < kv1.second){
                    cur_res += kv2.second;
                }
            }
            res = min(res, cur_res);
        }
        return res;
    }
};

int main(){
    Solution s;
    string word = "aabcaba";
    int k = 0;
    cout << s.minimumDeletions(word, k) << endl;
}
