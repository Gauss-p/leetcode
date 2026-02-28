#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&](vector<int>& a, vector<int>& b){
            return a[k] > b[k];
        });
        return score;
    }
};

int main(){
    Solution s;
    vector<vector<int>> score = {{10,6,9,1}, {7,5,11,2},{4,8,3,15}};
    int k = 2;
    vector<vector<int>> res = s.sortTheStudents(score, k);
    for (auto i : res){
        for (int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
