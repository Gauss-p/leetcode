#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> res;
        int n = height.size();
        for (int i=1; i<n; i++){
            if (height[i-1] > threshold){
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> height = {1,2,3,4,5};
    int threshold = 2;
    vector<int> res = s.stableMountains(height, threshold);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
