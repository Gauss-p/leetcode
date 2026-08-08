#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> suf(n+1, 0);
        suf[n] = m;
        int j = m-1;
        for (int i=n-1; i>=0; i--){
            if (j >= 0 && word1[i] == word2[j]){
                j -= 1;
            }
            suf[i] = j+1;
        }

        vector<int> res;
        j = 0;
        bool changed = false;
        for (int i=0; i<n; i++){
            if (word1[i] == word2[j]){
                res.push_back(i);
                j++;
            }
            else{
                if ((!changed) && suf[i+1] <= j+1){
                    res.push_back(i);
                    changed = true;
                    j++;
                }
            }
            if (j == m){
                return res;
            }
        }
        return {};
    }
};

int main(){
    Solution s;
    string word1 = "abc", word2 = "ab";
    vector<int> res = s.validSequence(word1, word2);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
