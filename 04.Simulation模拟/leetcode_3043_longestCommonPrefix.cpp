#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for (int x : arr2){
            for (int y=x; y; y/=10){
                st.insert(y);
            }
        }
        int res = 0;
        for (int x : arr1){
            int length = to_string(x).size();
            for (int y=x; y; y/=10){
                if (st.count(y)) res = max(res, length);
                length--;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr1 = {1,10,100}, arr2 = {1000};
    cout << s.longestCommonPrefix(arr1, arr2) << endl;
}
