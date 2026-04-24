#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int res = -1;
        for (int i=1; i<n-1; i++){
            if (num[i-1] == num[i] && num[i] == num[i+1]){
                res = max(res, num[i]-'0');
            }
        }
        string ans(3, '0'+res);
        return res==-1 ? "" : ans;
    }
};

int main(){
    Solution s;
    string num = "6777133339";
    cout << s.largestGoodInteger(num) << endl;
}
