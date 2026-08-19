#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> seats;
        for (auto& rs : reservedSeats){
            seats[rs[0]].insert(rs[1]);
        }

        int res = (n-seats.size())*2;
        for (auto& kv : seats){
            int i = kv.first;
            unordered_set<int> curRow = kv.second;
            bool flag = true;
            for (int s=2; s<=9; s++){
                if (curRow.count(s)){
                    flag = false;
                    break;
                }
            }
            if (flag){
                res += 2;
                continue;
            }

            for (int beg=2; beg<=6; beg+=2){
                bool canSit = true;
                for (int s=beg; s<=beg+3; s++){
                    if (curRow.count(s)){
                        canSit = false;
                    }
                }
                flag |= canSit;
                if (flag){
                    break;
                }
            }
            if (flag){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 3;
    vector<vector<int>> reservedSeats = {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}};
    cout << s.maxNumberOfFamilies(n, reservedSeats) << endl;
}
