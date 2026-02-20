#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string res;
        for (auto c : s){
            if (c == '*'){
                res.resize(res.size()-1);
            }
            else{
                res += c;
            }
        }
        return res;
    }
};

int main(){
    Solution so;
    string s = "leet***cod**e*";
    cout << so.removeStars(s) << endl;
}
