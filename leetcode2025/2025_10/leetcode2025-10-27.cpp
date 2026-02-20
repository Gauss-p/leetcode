#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    int myCount(string& s){
        int ans = 0;
        for (auto&c : s){
            ans += (c-'0');
        }
        return ans;
    }
public:
    int numberOfBeams(vector<string>& bank) {
        int last = 0;
        int res = 0;
        for (int i=0; i<bank.size(); i++){
            int cur = myCount(bank[i]);
            if (cur > 0){
                res += last*cur;
                last = cur;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> bank = {"011001","000000","010100","001000"};
    cout << s.numberOfBeams(bank) << endl;
}
