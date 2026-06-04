#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;
        for (int i=num1; i<=num2; i++){
            string s = to_string(i);
            for (int j=1; j<s.size()-1; j++){
                if ((s[j-1] < s[j] && s[j+1] < s[j]) || (s[j-1] > s[j] && s[j+1] > s[j])){
                    res++;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int num1 = 120, num2 = 130;
    cout << s.totalWaviness(num1, num2) << endl;
}
