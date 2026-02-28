#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int n;
    string w;

    long long myCount(int m){
        long long res = 0;
        long long l = 0;
        long long cnt = 0;
        unordered_map<char, long long> vowel;
        for (int r=0; r<n; r++){
            if (w[r]=='a' || w[r]=='e' || w[r]=='i' || w[r]=='o' || w[r]=='u'){
                vowel[w[r]]++;
            }
            else{
                cnt++;
            }

            while (vowel.size()==5 && cnt>=m){
                if (w[l]=='a' || w[l]=='e' || w[l]=='i' || w[l]=='o' || w[l]=='u'){
                    vowel[w[l]]--;
                    if (vowel[w[l]] == 0){
                        vowel.erase(w[l]);
                    }
                }
                else{
                    cnt--;
                }
                l++;
            }
            res += l;
        }
        return res;
    }
public:
    long long countOfSubstrings(string word, int k) {
        n = word.size();
        w = word;
        return myCount(k)-myCount(k+1);
    }
};

int main(){
    Solution s;
    string word = "aeiou";
    int k = 0;
    cout << s.countOfSubstrings(word, k) << endl;
}
