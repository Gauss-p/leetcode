#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<int> pos;
        vector<char> letters;
        for (int i=0; i<n; i++){
            if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                pos.push_back(i);
                letters.push_back(s[i]);
            }
        }
        sort(letters.begin(), letters.end());
        for (int i=0; i<pos.size(); i++){
            int indx = pos[i];
            s[indx] = letters[i];
        }
        return s;
    }
};

int main(){
    Solution sl;
    string s = "lEetcOde";
    cout << sl.sortVowels(s) << endl;
}
