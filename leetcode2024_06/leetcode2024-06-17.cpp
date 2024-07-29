#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool a_in_b(string a, string b){
        int indx1 = 0;
        bool flag = false;
        for (int indx2=0; indx2 < b.size(); indx2++){
            if (a[indx1] == b[indx2]){
                indx1++;
            }
            if (indx1 == a.size()){
                flag = true;
                break;
            }
        }
        return flag;
    }
    int findLUSlength(vector<string>& strs) {
        int res = -1;
        int n = strs.size();
        for (int i=0; i<n; i++){
            string tmp1 = strs[i];
            bool flag = true;
            for (int j=0; j<n; j++){
                string tmp2 = strs[j];
                if (j == i || tmp1.size() > tmp2.size()){
                    continue;
                }
                if (a_in_b(tmp1, tmp2)){
                    flag = false;
                    break;
                }
            }
            if (flag) res = max(res, (int)tmp1.size());
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> strs = {"aba","cdc","eae"};
    cout << s.findLUSlength(strs) << endl;
}
