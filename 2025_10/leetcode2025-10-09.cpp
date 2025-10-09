#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int m = mana.size(), n = skill.size();
        vector<long long> last(n, 0);
        for (int i=0; i<m; i++){
            long long time = 0;
            for (int j=0; j<n; j++){
                if (time < last[j]){
                    time = last[j];
                }
                time += 1ll*skill[j]*mana[i];
            }
            last[n-1] = time;
            for (int j=n-2; j>=0; j--){
                last[j] = last[j+1]-skill[j+1]*mana[i];
            }
        }
        return last[n-1];
    }
};

int main(){
    Solution s;
    vector<int> skill = {1,5,2,4}, mana = {5,1,4,2};
    cout << s.minTime(skill, mana) << endl;
}
