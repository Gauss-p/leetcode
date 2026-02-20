#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    string my_replace(string old, char a, char b){
        string ns;
        for (auto& c : old){
            if (c == a){
                ns += b;
            }
            else{
                ns += c;
            }
        }
        return ns;
    }
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string mx = s, mn = s;
        int n = s.size();
        for (int i=0; i<n; i++){
            if (mx[i] != '9'){
                mx = my_replace(mx, mx[i], '9');
                break;
            }
        }
        if (mn[0] != '1'){
            mn = my_replace(mn, mn[0], '1');
        }
        else{
            for (int i=0; i<n; i++){
                if (mn[i]-'0' > 1){
                    mn = my_replace(mn, mn[i], '0');
                    break;
                }
            }
        }
        return stoi(mx)-stoi(mn);
    }
};

int main(){
    Solution s;
    int num = 555;
    cout << s.maxDiff(num) << endl;
}
