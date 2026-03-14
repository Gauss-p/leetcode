#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        if ((3<<(n-1)) < k){
            return "";
        }
        k -= 1;
        string res(n, 'a');
        res[0] += (k>>(n-1));
        vector<vector<int>> dic = {{1,2},{0,2},{0,1}};
        for (int i=1; i<n; i++){
            res[i] += dic[res[i-1]-'a'][(k>>(n-i-1))&1];
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 1, k = 3;
    cout << s.getHappyString(n, k) << endl;
}
