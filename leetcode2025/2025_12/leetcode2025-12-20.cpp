#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size();
        int res = 0;
        for (int j=0; j<n; j++){
            for (int i=0; i<m-1; i++){
                if (strs[i][j] > strs[i+1][j]){
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> strs = {"cba","daf","ghi"};
    cout << s.minDeletionSize(strs) << endl;
}
