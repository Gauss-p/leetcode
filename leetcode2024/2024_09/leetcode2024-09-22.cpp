#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size() == 0){
            return n==1 ? 1 : -1;
        }
        vector<int> cnt1(n+1, 0), cnt2(n+1, 0);
        for (auto p : trust){
            cnt1[p[0]]++;
            cnt2[p[1]]++;
        }
        for (int i=1; i<=n; i++){
            if (cnt2[i] == n-1 && cnt1[i] == 0){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    int n = 2;
    vector<vector<int>> trust = {{1,2}};
    cout << s.findJudge(n, trust) << endl;
}
