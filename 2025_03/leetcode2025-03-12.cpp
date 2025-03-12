#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int res = 0, n = word.size();
        for (int i=0; i<n; i++){
            unordered_map<char, int> vowel;
            int cnt = 0;
            for (int j=i; j<n; j++){
                if (word[j]=='a' || word[j]=='e' || word[j]=='i' || word[j]=='o' || word[j]=='u'){
                    vowel[word[j]]++;
                }
                else{
                    cnt++;
                }
                if (vowel.size()==5 && cnt==k){
                    res++;
                }
                if (cnt>k){
                    continue;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string word = "ieaouqqieaouqq";
    int k = 1;
    cout << s.countOfSubstrings(word, k) << endl;
}
