#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26, 0);
        for (auto& c : word){
            cnt[c-'a']++;
        }
        sort(cnt.begin(), cnt.end(), greater<int>());
        int res = 0;
        for (int i=0; i<26; i++){
            res += cnt[i]*(i/8+1);
        }
        return res;
    }
};

int main(){
    Solution s;
    string word = "abcde";
    cout << s.minimumPushes(word) << endl;
}
