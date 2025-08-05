#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int res = fruits.size();
        int n = fruits.size();
        unordered_map<int, int> used;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (used[j] == 0 && baskets[j] >= fruits[i]){
                    used[j] = 1;
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> fruits = {4,2,5};
    vector<int> baskets = {3,5,4};
    cout << s.numOfUnplacedFruits(fruits, baskets) << endl;
}
