#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
private:
    unordered_set<int> calcSpace(vector<int> fence, int mx){
        fence.insert(fence.begin(), 1);
        fence.push_back(mx);
        sort(fence.begin(), fence.end());
        unordered_set<int> space;
        for (int i=0; i<fence.size(); i++){
            for (int j=i+1; j<fence.size(); j++){
                space.insert(fence[j]-fence[i]);
            }
        }
        return space;
    }
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int modNum = 1e9+7;
        unordered_set<int> hSpace = calcSpace(hFences, m);
        unordered_set<int> vSpace = calcSpace(vFences, n);

        int res = -1;
        vector<int> hs(hSpace.begin(), hSpace.end());
        for (int i : hs){
            if (vSpace.count(i)){
                res = max(res, i);
            }
        }

        if (res == -1){
            return res;
        }
        return 1ll*res*res%modNum;
    }
};

int main(){
    Solution s;
    int m = 4, n = 3;
    vector<int> hFences = {2,3}, vFences = {2};
    cout << s.maximizeSquareArea(m, n, hFences, vFences) << endl;
}
