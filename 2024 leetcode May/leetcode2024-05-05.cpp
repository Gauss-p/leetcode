#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        for (int i=0; i<n; i++){
            if (k != 0){
                if (k > 0){
                    for (int j=1; j<=k; j++){
                        res[i] += code[(i+j)%n];
                    }
                }
                else{
                    for (int j=1; j<=(-k); j++){
                        res[i] += code[((i-j)+n*(-k))%n];
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> code = {5,7,1,4};
    int k = 3;
    vector<int> res =  s.decrypt(code, k);
    for (int i : res){
        cout << i << " ";
    }
}
