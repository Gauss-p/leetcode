#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        unordered_map<int, int> ns;
        for (int i : spaces) ns[i]++;
        int n = s.size();
        string res;
        for (int i=0; i<n; i++){
            if (ns[i]){
                res += " ";
            }
            res += s[i];
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "LeetcodeHelpsMeLearn";
    vector<int> spaces = {8,3,15};
    cout << sl.addSpaces(s, spaces) << endl;
}
