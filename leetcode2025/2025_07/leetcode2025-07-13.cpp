#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int n = trainers.size(), m = players.size();
        int j = 0;
        for (int i=0; i<n; i++){
            if (j < m && players[j] <= trainers[i]){
                j++;
            }
        }
        return j;
    }
};

int main(){
    Solution s;
    vector<int> players = {4,7,9}, trainers = {8,2,5,8};
    cout << s.matchPlayersAndTrainers(players, trainers) << endl;
}
