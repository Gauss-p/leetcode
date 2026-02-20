#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int res = 0;
        int n = hours.size();
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                if ((hours[i]+hours[j])%24 == 0){
                    res++;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> hours = {12,12,30,24,24};
    cout << s.countCompleteDayPairs(hours) << endl;
}
