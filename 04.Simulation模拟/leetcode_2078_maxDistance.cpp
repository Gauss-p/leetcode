#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        if (colors[0] != colors[n-1]){
            return n-1;
        }
        int res = 0;
        for (int i=0; i<n; i++){
            if (colors[i] != colors[n-1]){
                res = n-1-i;
                break;
            }
        }
        for (int i=n-1; i>=0; i--){
            if (colors[i] != colors[0]){
                res = max(res, i);
                break;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> colors = {1,1,1,6,1,1,1};
    cout << s.maxDistance(colors) << endl;
}
