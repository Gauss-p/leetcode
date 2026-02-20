#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        for (int i=1; i<=n/2; i++){
            res.push_back(i);
            res.push_back(-i);
        }
        if (n&1){
            res.push_back(0);
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 5;
    vector<int> res = s.sumZero(n);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
