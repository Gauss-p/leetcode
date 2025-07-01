#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int res = 0;
        int n = word.size();
        int i = 0;
        while (i < n){
            int j = i;
            while (j<n && word[j] == word[i]){
                j++;
            }
            res += j-i-1;
            i = j;
        }
        return res+1;
    }
};

int main(){
    Solution s;
    string word = "abbcccc";
    cout << s.possibleStringCount(word) << endl;
}
