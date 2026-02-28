#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        string chars = "_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        unordered_map<string, int> mp;
        mp["electronics"] = 0;
        mp["grocery"] = 1;
        mp["pharmacy"] = 2;
        mp["restaurant"] = 3;
        vector<vector<string>> tot(4);
        for (int i=0; i<code.size(); i++){
            string curCode = code[i], b = businessLine[i];
            bool flag = true;
            for (auto& c : curCode){
                if (count(chars.begin(), chars.end(), c) == 0){
                    flag = false;
                    break;
                }
            }
            if (curCode.size()>0 && flag && mp.count(b) && isActive[i]){
                tot[mp[b]].push_back(curCode);
            }
        }
        for (int i=0; i<4; i++){
            sort(tot[i].begin(), tot[i].end());
        }
        vector<string> res;
        for (int i=0; i<4; i++){
            for (auto& s : tot[i]){
                res.push_back(s);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> code = {"SAVE20","","PHARMA5","SAVE@20"}, businessLine = {"restaurant","grocery","pharmacy","restaurant"};
    vector<bool> isActive = {true,true,true,true};
    vector<string> res = s.validateCoupons(code, businessLine, isActive);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
