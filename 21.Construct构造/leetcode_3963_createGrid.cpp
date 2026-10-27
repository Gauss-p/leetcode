#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res = vector(m-1, string(n-1, '#')+".");
        res.insert(res.begin(), string(n, '.'));
        return res;
    }
};

int main(){
    Solution s;
    int m = 2, n = 3;
    vector<string> res = s.createGrid(m, n);
    for (auto& r : res){
        cout << r << endl;
    }
}
