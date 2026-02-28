#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1){
            return word;
        }
        int n = word.size();
        int i = 0, j = 1, k = 0;
        while (j+k<n){
            if (word[i+k] == word[j+k]){
                k++;
            }
            else if (word[i+k] < word[j+k]){
                i = i+k+1;
                k = 0;
                if (i >= j){
                    j = i+1;
                }
            }
            else{
                j = j+k+1;
                k = 0;
            }
        }
        return word.substr(i, n-(numFriends-1));
    }
};

int main(){
    Solution s;
    string word = "dbca";
    int numFriends = 2;
    cout << s.answerString(word, numFriends) << endl;
}
