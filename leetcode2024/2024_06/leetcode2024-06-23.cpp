#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        bool first;
        if (count(upper.begin(), upper.end(), word[0])){
            first = true;
        }
        else{
            first = false;
        }
        int cnt = 0;
        for (int i=1; i<(int)word.size(); i++){
            if (count(upper.begin(), upper.end(), word[i]) == 0){
                cnt++;
            }
        }
        if (cnt == (int)word.size()-1 || (first == true && cnt == 0)){
            return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    string word = "GooglE";
    cout << s.detectCapitalUse(word) << endl;
}
