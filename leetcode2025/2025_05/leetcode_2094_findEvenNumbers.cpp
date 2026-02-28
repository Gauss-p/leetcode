#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    bool check(unordered_map<int, int> mp1, unordered_map<int, int> mp2){
        for (auto&kv : mp1){
            if (kv.second > mp2[kv.first]){
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> mp2;
        for (int i : digits){
            mp2[i]++;
        }
        int n = digits.size();
        vector<int> res;
        for (int i=100; i<1000; i+=2){
            int tmp = i;
            unordered_map<int, int> mp1;
            while (tmp){
                mp1[tmp%10]++;
                tmp /= 10;
            }
            if (check(mp1, mp2)){
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> digits = {2,1,3,0};
    vector<int> res = s.findEvenNumbers(digits);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
