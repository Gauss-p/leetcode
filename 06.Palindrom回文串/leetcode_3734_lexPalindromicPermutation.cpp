#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int m;
    char middle;
    string left, right, Target;
    vector<int> halfCnt;

    string dfs(int indx, bool isLarger){
        if (indx == m){
            string ans;
            if (middle){
                ans = left+middle+right;
            }
            else{
                ans = left+right;
            }
            return (ans > Target ? ans : "");
        }

        char begin = (isLarger ? 'a' : Target[indx]);
        for (char cur=begin; cur<='z'; cur++){
            if (halfCnt[cur-'a'] <= 0){
                continue;
            }

            left += cur;
            right = cur+right;
            halfCnt[cur-'a'] -= 1;
            bool curLarger = isLarger | (cur > Target[indx]);
            string ans = dfs(indx+1, curLarger);

            if (ans.size()){
                return ans;
            }

            left = left.substr(0, left.size()-1);
            right = right.substr(1, right.size()-1);
            halfCnt[cur-'a']++;
        }
        return "";
    }

public:
    string lexPalindromicPermutation(string s, string target) {
        Target = target;
        int n = s.size();
        unordered_map<char, int> cnt;
        for (auto& c : s) cnt[c]++;
        int oddNum = 0;
        halfCnt.resize(26, 0);
        for (auto& kv : cnt){
            if (kv.second & 1){
                middle = kv.first;
                oddNum++;
            }
            halfCnt[kv.first-'a'] = kv.second/2;
        }

        if (oddNum > 1) return "";

        m = n/2;
        left = "";
        right = "";
        return dfs(0, false);
    }
};

int main(){
    Solution sl;
    string s = "baba";
    string target = "abba";
    cout << sl.lexPalindromicPermutation(s, target) << endl;
}
