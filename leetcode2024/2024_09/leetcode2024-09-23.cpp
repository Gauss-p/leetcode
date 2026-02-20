#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_i = values[0];
        int res = 0, n = values.size();
        for (int i=1; i<n; i++){
            int tmp_j = values[i]-i;
            res = max(res,max_i+tmp_j);
            max_i = max(max_i, values[i]+i);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> values = {8,1,5,2,6};
    cout << s.maxScoreSightseeingPair(values) << endl;
}
