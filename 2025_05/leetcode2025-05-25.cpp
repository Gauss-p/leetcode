#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> cnt;
        for (string s : words){
            cnt[s]++;
        }
        vector<string> keys;
        for (auto& kv : cnt){
            keys.push_back(kv.first);
        }

        bool same = false;
        int res = 0;
        unordered_map<string, int> visited;
        for (auto& kv : cnt){
            string s = kv.first;
            int t = kv.second;

            if (visited[s] == 1){
                continue;
            }
            char a = s[0], b = s[1];
            string opposite;
            opposite = b;
            opposite += a;

            // 注意这里索引的时候不能用unordered_map，否则会出现莫名的跳过
            int n1 = cnt[s];
            int n2 = cnt[opposite];
            if (a != b){
                res += 2*min(n1, n2)*2;
                visited[opposite] = 1;
            }
            else{
                if (cnt[s]%2 == 1){
                    same = true;
                }
                res += 2*(cnt[s]-cnt[s]%2);
            }
        }
        // for (string s : keys){
        //     if (cnt[s] == 0){
        //         continue;
        //     }
        //     char a = s[0], b = s[1];
        //     string opposite;
        //     opposite = b;
        //     opposite += a;

        //     if (a != b){
        //         res += 2*min(cnt[s], cnt[opposite])*2;
        //         cnt[opposite] = 0;
        //     }
        //     else{
        //         if (cnt[s]%2 == 1){
        //             same = true;
        //         }
        //         res += 2*(cnt[s]-cnt[s]%2);
        //     }
        // }

        if (same){
            res += 2;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> words = {"lc","cl","gg"};
    cout << s.longestPalindrome(words) << endl;
}
