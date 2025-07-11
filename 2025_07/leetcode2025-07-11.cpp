#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> tot;
        int totSize = 0;
        for (int i=0; i<n; i++){
            if (tot.empty() || tot[totSize-1][1] < meetings[i][0]){
                tot.push_back(meetings[i]);
                totSize++;
            }
            else{
                tot[totSize-1][1] = max(tot[totSize-1][1], meetings[i][1]);
            }
        }
        int res = days;
        for (auto& i : tot){
            res -= (i[1]-i[0]+1);
        }
        return res;
    }
};

int main(){
    Solution s;
    int days = 10;
    vector<vector<int>> meetings = {{5,7},{1,3},{9,10}};
    cout << s.countDays(days, meetings) << endl;
}
