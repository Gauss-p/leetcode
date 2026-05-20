#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n, 0);
        res[n-1] = n;
        int cur = n;
        unordered_map<int, int> cnt;
        for (int i=n-1; i>=1; i--){
            int a = A[i], b = B[i];
            if (cnt[a] == 0){
                cnt[a] = 1;
                cur--;
            }
            if (cnt[b] == 0){
                cnt[b] = 1;
                cur--;
            }
            res[i-1] = cur;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> A = {1,3,2,4}, B = {3,1,2,4};
    vector<int> res = s.findThePrefixCommonArray(A,B);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
