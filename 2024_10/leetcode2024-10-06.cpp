#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = 0, minGas = INT_MAX, minIndex = -1;
        int n = gas.size();
        for (int i=0; i<n; i++){
            sumGas += gas[i]-cost[i];
            if (sumGas < minGas && sumGas < 0){
                minGas = sumGas;
                minIndex = i;
            }
        }
        if (sumGas < 0) return -1;
        return (minIndex+1)%n;
        // int n = gas.size();
        // for (int i=0; i<n; i++){
        //     gas[i] -= cost[i];
        // }
        // for (int i=0; i<n; i++){
        //     int tmp = 0;
        //     bool flag = true;
        //     for (int j=0; j<n; j++){
        //         tmp += gas[(i+j)%n];
        //         if (tmp < 0){
        //             flag = false;
        //             break;
        //         }
        //     }
        //     if (flag){
        //         return i;
        //     }
        // }
        // return -1;
    }
};

int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    Solution s;
    cout << s.canCompleteCircuit(gas, cost) << endl;
}
