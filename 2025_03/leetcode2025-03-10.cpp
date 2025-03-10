#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int tmp = 0, res = 0;
        string s_num = to_string(num);
        for (int i=0; i<s_num.size(); i++){
            tmp = tmp*10+(s_num[i]-'0');
            if (i < k-1) continue;
            if (tmp != 0 && num%tmp == 0){
                res++;
            }
            tmp = tmp%((int)pow(10, k-1));
        }
        return res;
    }
};

int main(){
    Solution s;
    int num=240, k=2;
    cout << s.divisorSubstrings(num, k) << endl;
}
