#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k){
            string ns;
            for (int i=0; i<s.size(); i+=k){
                int cnt = 0;
                for (int j=i; j<min(i+k, (int)s.size()); j++){
                    cnt += (s[j]-'0');
                }
                ns += to_string(cnt);
            }
            s = ns;
        }
        return s;
    }
};

int main(){
    Solution sl;
    string s = "11111222223";
    int k = 3;
    cout << sl.digitSum(s, k) << endl;
}
