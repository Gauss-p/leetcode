#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int res = count(s.begin(), s.end(), 'a');
        int cnt = 0;
        int totA = res;
        for (auto& c : s){
            if (c == 'b'){
                cnt++;
            }
            else{
                totA--;
            }
            res = min(res, cnt+totA);
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "aababbab";
    cout << sl.minimumDeletions(s) << endl;
}
