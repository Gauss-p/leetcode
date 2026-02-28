#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3){
            return false;
        }
        int is_vowel=0, is_consonant=0;
        for (auto&c : word){
            if ((c-'a'>=0 && c-'a'<26) || (c-'A'>=0 && c-'A'<26)){
                char cur = c;
                if (c-'A' >= 0 && c-'A'<26){
                    cur = 'a'+(c-'A');
                }
                if (cur=='a' || cur=='e' || cur=='i' || cur=='o' || cur=='u'){
                    is_vowel = 1;
                }
                else{
                    is_consonant = 1;
                }
            }
            else if (c-'0'<0 || c-'0'>9){
                return false;
            }
        }
        return is_vowel+is_consonant==2;
    }
};

int main(){
    Solution s;
    string word = "234Adas";
    cout << s.isValid(word) << endl;
}
