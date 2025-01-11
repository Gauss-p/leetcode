#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string s1 = to_string(num1), s2 = to_string(num2), s3 = to_string(num3);
        int n = min(s1.size(), min(s2.size(), s3.size()));
        string key;
        int sz1 = s1.size(), sz2 = s2.size(), sz3 = s3.size();
        for (int i=0; i<n; i++){
            int a = s1[sz1-i-1]-'0', b = s2[sz2-i-1]-'0', c = s3[sz3-i-1]-'0';
            key += to_string(min(a, min(b, c)));
        }
        int res = 0;
        for (int i=n-1; i>=0; i--){
            res = res*10+(key[i]-'0');
        }
        return res;
    }
};

int main(){
    Solution s;
    int num1 = 1, num2 = 10, num3 = 1000;
    cout << s.generateKey(num1,num2,num3) << endl;
}
