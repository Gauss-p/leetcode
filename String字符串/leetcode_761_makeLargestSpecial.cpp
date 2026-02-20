#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        int start = 0, i = 0, cnt = 0;
        vector<string> specialStrings;
        while (i<s.size()){
            if (s[i] == '1'){
                cnt++;
            }
            else{
                cnt--;
            }
            if (cnt == 0){
                string inner = s.substr(start+1, i-start-1);
                string newStr = "1"+makeLargestSpecial(inner)+"0";
                specialStrings.push_back(newStr);
                start = i+1;
            }
            i++;
        }
        sort(specialStrings.begin(), specialStrings.end());
        string res;
        for (int i=specialStrings.size()-1; i>=0; i--){
            res += specialStrings[i];
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "11011000";
    cout << sl.makeLargestSpecial(s) << endl;
}
