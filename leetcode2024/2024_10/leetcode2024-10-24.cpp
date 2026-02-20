#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int maxIndex = 0;
        int win = 0;
        for (int i=1; i<skills.size()&&win<k; i++){
            if (skills[i] > skills[maxIndex]){
                maxIndex = i;
                win = 0;
            }
            win++;
        }
        return maxIndex;
    }
};

int main(){
    Solution s;
    vector<int> skills = {4,2,6,3,9};
    int k = 2;
    cout << s.findWinningPlayer(skills, k) << endl;
}
