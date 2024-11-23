#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> mp(10, vector<int>(11));
        for (auto i : pick){
            mp[i[0]][i[1]]++;
        }
        int res = 0;
        for (int i=0; i<10; i++){
            if (*max_element(mp[i].begin(), mp[i].end()) > i){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 4;
    vector<vector<int>> pick = {{0,0},{1,0},{1,0},{2,1},{1,0},{2,1},{2,1},{2,0}};
    cout << s.winningPlayerCount(n, pick) << endl;
}
