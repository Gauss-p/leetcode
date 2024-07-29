#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> in_degrees(n);
        for (auto &e : edges){
            in_degrees[e[1]]++;
        }
        int cnt = 0, res = 0;
        for (int i=0; i<n; i++){
            if (in_degrees[i] == 0){
                cnt++;
                res = i;
            }
        }
        return cnt==1 ? res : -1;
    }
};

int main(){
    Solution s;
    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2}};
    cout << s.findChampion(n, edges) << endl;
    return 0;
}
