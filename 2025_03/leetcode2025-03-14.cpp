#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isBalanced(string num) {
        int odd = 0, even = 0;
        int n = num.size();
        for (int i=0; i<n; i++){
            if (i&1){
                odd += (num[i]-'0');
            }
            else{
                even += (num[i]-'0');
            }
        }
        return odd == even;
    }
};

int main(){
    Solution s;
    string num = "1234";
    cout << s.isBalanced(num) << endl;
}
