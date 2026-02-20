#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, -1);
        unordered_map<int, int> rainDays;
        unordered_map<int, int> visited;
        vector<int> sunny;
        for (int i=0; i<n; i++){
            if (rains[i] == 0){
                sunny.push_back(i);
            }
            else{
                if (visited[rains[i]] == 1){
                    int last = rainDays[rains[i]];
                    if (sunny.size()==0 || sunny.back()<last){
                        return {};
                    }
                    int indx = lower_bound(sunny.begin(), sunny.end(), last)-sunny.begin();
                    int day = sunny[indx];
                    sunny.erase(sunny.begin()+indx);
                    res[day] = rains[i];
                }
                visited[rains[i]] = 1;
                rainDays[rains[i]] = i;
            }
        }
        for (auto& d : sunny){
            res[d] = 1;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> rains = {1,2,0,0,2,1};
    vector<int> res = s.avoidFlood(rains);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
