#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)){
            res += '-';
        }
        long long nume = abs((long long) numerator);
        long long deno = abs((long long) denominator);
        string s = to_string(nume);
        
        bool flag = false;
        long long cur = 0;
        for (auto& c : s){
            cur = cur*10+(c-'0');
            if (flag || cur >= deno){
                flag = true;
                res += ('0'+(cur/deno));
                cur %= deno;
            }
            else if (flag && cur < deno){
                res += '0';
            }
        }
        if (res.size() == 0){
            res += '0';
        }
        if (cur == 0){
            return res;
        }
        res += '.';
        unordered_map<int, int> visited;
        int indx = res.size();
        while (visited.count(cur) == 0){
            if (cur == 0){
                return res;
            }
            visited[cur] = indx;
            cur = cur*10;
            if (cur >= deno){
                res += ('0'+(cur/deno));
                cur %= deno;
            }
            else{
                res += '0';
            }
            indx += 1;
        }
        if (cur == 0){
            return res;
        }
        res = res.substr(0, visited[cur]) + '(' + res.substr(visited[cur], res.size()-visited[cur]) + ')';
        return res;
    }
};

int main(){
    Solution s;
    int numerator = 4, denominator = 333;
    cout << s.fractionToDecimal(numerator, denominator) << endl;
}
