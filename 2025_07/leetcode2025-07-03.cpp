#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string w = "a";
        while (w.size()<k){
            string cur;
            for (auto& c : w){
                cur += ('a'+((c-'a')+1)%26);
            }
            w += cur;
        }
        return w[k-1];
    }
};

int main(){
    Solution s;
    int k = 5;
    cout << s.kthCharacter(k) << endl;
}
