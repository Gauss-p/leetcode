#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        int tmpMax = arr[n-1];
        for (int i=n-2; i>=0; i--){
            res[i] = tmpMax;
            tmpMax = max(tmpMax, arr[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr = {17,18,5,4,6,1};
    vector<int> res = s.replaceElements(arr);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
