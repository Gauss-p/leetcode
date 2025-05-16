#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    bool check(string s1, string s2){
        if (s1.size() != s2.size() || s1==s2){
            return false;
        }
        int diff = 0;
        for (int i=0; i<s1.size(); i++){
            if (s1[i] != s2[i]){
                diff++;
            }
            if (diff >= 2){
                return false;
            }
        }
        return true;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        vector<int> dp(n, 0);
        vector<int> from_(n, -1);
        int max_indx = n-1;
        for (int i=n-1; i>=0; i--){
            for (int j=i+1; j<n; j++){
                if (dp[j] > dp[i] && groups[i] != groups[j] && check(words[i], words[j])){
                    dp[i] = dp[j];
                    from_[i] = j;
                }
            }
            dp[i]++;
            if (dp[i] > dp[max_indx]){
                max_indx = i;
            }
        }

        vector<string> res;
        while (max_indx != -1){
            res.push_back(words[max_indx]);
            max_indx = from_[max_indx];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> words = {"bab","dab","cab"};
    vector<int> groups = {1,2,2};
    vector<string> res = s.getWordsInLongestSubsequence(words, groups);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
