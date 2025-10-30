#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = target[0];
        for (int i=0; i<target.size()-1; i++){
            res += max(0, target[i+1]-target[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> target = {1,2,3,2,1};
    cout << s.minNumberOperations(target) << endl;
}
