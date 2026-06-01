#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int res = 0;
        for (int i=0; i<cost.size(); i+=3){
            res += cost[i];
            if (i+1 < cost.size()){
                res += cost[i+1];
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> cost = {1,2,3};
    cout << s.minimumCost(cost) << endl;
}
