#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        vector<int> res(n, 0);
        for (int i=0; i<n; i++){
            long long target = (success-1)/spells[i]+1;
            int indx = lower_bound(potions.begin(), potions.end(), target)-potions.begin();
            res[i] = potions.size()-indx;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> spells = {5,1,3}, potions = {1,2,3,4,5};
    int success = 7;
    vector<int> res = s.successfulPairs(spells, potions, success);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
