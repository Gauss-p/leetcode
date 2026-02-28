#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> cnt;
        int res = 0;
        for (auto& d : dominoes){
            int x=d[0], y=d[1];
            if (x>y){
                swap(x,y);
            }
            string k = to_string(x)+"_"+to_string(y);
            res += cnt[k];
            cnt[k]++;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> dominoes = {{1,2}, {2,1}, {3,4}, {5,6}};
    cout << s.numEquivDominoPairs(dominoes) << endl;
}
