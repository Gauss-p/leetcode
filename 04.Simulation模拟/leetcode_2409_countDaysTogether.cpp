#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> preSum(14, 0);
        for (int i=0; i<13; i++){
            preSum[i+1] = preSum[i]+days[i];
        }
        int aad = preSum[stoi(arriveAlice.substr(0,2))]+stoi(arriveAlice.substr(3));
        int lad = preSum[stoi(leaveAlice.substr(0,2))]+stoi(leaveAlice.substr(3));
        int abd = preSum[stoi(arriveBob.substr(0,2))]+stoi(arriveBob.substr(3));
        int lbd = preSum[stoi(leaveBob.substr(0,2))]+stoi(leaveBob.substr(3));
        int start = max(aad, abd), end = min(lad, lbd);
        return max(0, end-start+1);
    }
};

int main(){
    Solution s;
    string arriveAlice = "08-15";
    string leaveAlice = "08-18";
    string arriveBob = "08-16";
    string leaveBob = "08-19";
    cout << s.countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob) << endl;
}
