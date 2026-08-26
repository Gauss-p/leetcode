#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> pos;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='1'){
                pos.push_back(i);
            }
        }

        string res = "";
        vector<string> cur;
        for (int i=0; i<pos.size(); i++){
            if (cur.size() > 0){
                cur.push_back(string(pos[i]-pos[i-1]-1, '0'));
            }
            cur.push_back("1");
            if (i < k-1){
                continue;
            }
            string curS = "";
            for (auto& c : cur){
                curS += c;
            }
            if (res == "" || curS.size()<res.size() || (curS.size()==res.size() && curS<res)){
                res = curS;
            }
            cur.erase(cur.begin());
            if (cur.size()){
                cur.erase(cur.begin());
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "10001101";
    int k = 3;
    cout << sl.shortestBeautifulSubstring(s, k) << endl;
}
