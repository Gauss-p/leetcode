#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        if (word1.size() < word2.size()){
            return 0;
        }
        vector<int> cnt2(26, 0);
        for (auto s : word2){
            cnt2[s-'a']++;
        }
        vector<int> cnt1(26, 0);
        int n = word1.size();
        int l = 0, r = 0;
        cnt1[word1[r]-'a']++;
        long long res = 0;
        while (r<n){
            if (r-l+1 < word2.size()){
                r++;
                if (r == n){
                    break;
                }
                cnt1[word1[r]-'a']++;
                continue;
            }
            bool flag = true;
            for (int i=0; i<26; i++){
                if (cnt2[i] > cnt1[i]){
                    flag = false;
                    break;
                }
            }
            if (flag){
                res += n-r;
                // cout << l << " " << r << endl;
                // cout << n-r << endl;
                cnt1[word1[l]-'a']--;
                l++;
            }
            else{
                r++;
                if (r == n){
                    break;
                }
                cnt1[word1[r]-'a']++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string word1 = "bcca", word2 = "abc";
    cout << s.validSubstringCount(word1,word2) << endl;
}
