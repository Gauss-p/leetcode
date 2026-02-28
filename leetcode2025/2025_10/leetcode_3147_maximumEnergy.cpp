#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int res = INT_MIN;
        vector<int> tot(k, 0);
        for (int i=energy.size()-1; i>=0; i--){
            tot[i%k] += energy[i];
            if (tot[i%k] > res){
                res = tot[i%k];
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> energy = {5,2,-10,-5,1};
    int k = 3;
    cout << s.maximumEnergy(energy, k) << endl;
}
