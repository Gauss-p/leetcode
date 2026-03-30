#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> mp0, mp1;
        for (int i=0; i<s1.size(); i++){
            if (i&1){
                mp1[s1[i]]++;
                mp1[s2[i]]--;
            }
            else{
                mp0[s1[i]]++;
                mp0[s2[i]]--;
            }
        }
        for (auto& kv : mp1){
            if (kv.second != 0){
                return false;
            }
        }
        for (auto& kv : mp0){
            if (kv.second != 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    string s1 = "abcdba", s2 = "cabdab";
    cout << s.checkStrings(s1, s2) << endl;
}
