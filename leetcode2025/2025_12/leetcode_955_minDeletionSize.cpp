#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size();
        vector<string> tot(m);
        int res = 0;
        for (int j=0; j<n; j++){
            bool flag = true;
            for (int i=0; i<m-1; i++){
                if (tot[i]+strs[i][j] > tot[i+1]+strs[i+1][j]){
                    res++;
                    flag = false;
                    break;
                }
            }
            if (flag){
                for (int i=0; i<m; i++){
                    tot[i] += strs[i][j];
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> strs = {"ca","bb","ac"};
    cout << s.minDeletionSize(strs) << endl;
}
