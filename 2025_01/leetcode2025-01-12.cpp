#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res = 0;
        for (int i=0; i<32; i++){
            int tmp = 0;
            for (int j : candidates){
                if ((j>>i)&1){
                    tmp++;
                }
            }
            res = max(res, tmp);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> candidates = {16,17,71,62,12,24,14};
    cout << s.largestCombination(candidates) << endl;
}
