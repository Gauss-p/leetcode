#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b){
            return a[1]-a[0]>b[1]-b[0];
        });
        int res = 0;
        for (int i=tasks.size()-1; i>=0; i--){
            res = max(res+tasks[i][0], tasks[i][1]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> tasks = {{1,2},{2,4},{4,8}};
    cout << s.minimumEffort(tasks) << endl;
}
