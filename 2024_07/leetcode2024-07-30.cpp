#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int my_cal(int a, int b, int c){
        int res = 1;
        while (b--){
            res = (res*(a%c))%c;
        }
        return res;
    }
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> res;
        int n = variables.size();
        for (int i=0; i<n; i++){
            int first = my_cal(variables[i][0],variables[i][1],10);
            int second = my_cal(first, variables[i][2], variables[i][3]);
            if (second == target){
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> variables = {{2,3,3,10},{3,3,3,1},{6,1,1,4}};
    int target = 2;
    vector<int> res = s.getGoodIndices(variables, target);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
