#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int modNum = 1e9+7;
        int n = complexity.size();
        int res = 1;
        for (int i=1; i<n; i++){
            if (complexity[i] <= complexity[0]){
                return 0;
            }
            res = (1ll*res*i)%modNum;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> complexity = {1,2,3};
    cout << s.countPermutations(complexity) << endl;
}
