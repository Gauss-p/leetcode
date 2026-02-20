#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end());
        int n = capacity.size();
        int s = 0, tot = 0, res = 0;
        for (auto& i : apple) s += i;
        for (int i=n-1; i>=0; i--){
            if (tot >= s){
                return res;
            }
            tot += capacity[i];
            res++;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> apple = {1,3,2}, capacity = {4,3,1,5,2};
    cout << s.minimumBoxes(apple, capacity) << endl;
}
