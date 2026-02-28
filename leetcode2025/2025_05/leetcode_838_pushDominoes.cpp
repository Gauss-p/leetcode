#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L'+dominoes+'R';
        int n = dominoes.size();
        int pre = 0;
        string res;
        for (int i=1; i<n; i++){
            if (dominoes[i] == '.'){
                continue;
            }
            string tmp;
            int m = i-pre+1;
            if (dominoes[i] == dominoes[pre]){
                tmp = string(m-1, dominoes[i]);
            }
            else if (dominoes[i] == 'L'){
                tmp = string(m/2, 'R');
                if (m%2){
                    tmp += '.';
                }
                tmp += string(m/2-1, 'L');
            }
            else{
                tmp = 'L'+string(m-2, '.');
            }
            res += tmp;
            pre = i;
        }
        return res.substr(1);
    }
};

int main(){
    Solution s;
    string dominoes = ".L.R...LR..L..";
    cout << s.pushDominoes(dominoes) << endl;
}
