#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
private:
    long long calc(string curStr, string s, int limit){
        if (curStr.size() < s.size()){
            return 0;
        }
        if (curStr.size() == s.size()){
            return curStr>=s;
        }

        int tmpLength = curStr.size()-s.size();
        string suffix = curStr.substr(tmpLength, curStr.size()-tmpLength);
        long long ans = 0;

        for (int i=0; i<tmpLength; i++){
            if ((curStr[i]-'0') > limit){
                ans += 1ll*pow(limit+1, tmpLength-i);
                return ans;
            }
            ans += (curStr[i]-'0')*1ll*pow(limit+1, tmpLength-i-1);
        }
        if (suffix >= s){
            ans++;
        }
        return ans;
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string strStart = to_string(start-1), strFinish = to_string(finish);
        return calc(strFinish, s, limit)-calc(strStart, s, limit);
    }
};

int main(){
    Solution sl;
    int start = 1, finish = 6000, limit = 4;
    string s = "124";
    cout << sl.numberOfPowerfulInt(start, finish, limit, s) << endl;
}
