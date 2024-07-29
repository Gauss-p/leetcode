#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> res;
        for (int i=0; i<operations.size(); i++){
            auto s = operations[i];
            if (s != "C" && s != "D" && s != "+"){
                int tmp = 0;
                int op = s[0] == '-' ? -1 : 1;
                for (auto c : s){
                    if (c != '-'){
                        tmp = tmp*10+op*(c-'0');
                    }
                }
                res.push_back(tmp);
            }
            if (s == "C"){
                res.pop_back();
            }
            if (s == "D"){
                cout << i << endl;
                res.push_back(res.back()*2);
            }
            if (s == "+"){
                res.push_back(res[res.size()-2]+res[res.size()-1]);
            }
        }
        int ans = 0;
        for (auto i : res){
            ans += i;
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<string> operations = {"5","2","C","D","+"};
    cout << s.calPoints(operations) << endl;
    return 0;
}
