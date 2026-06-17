#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        long long length = 0;
        for (auto& c : s){
            if ('a' <= c && c <= 'z'){
                length++;
            }
            if (c == '*' && length >= 1){
                length--;
            }
            if (c == '#'){
                length *= 2;
            }
        }

        if (k >= length){
            return '.';
        }

        for (int i=s.size()-1; i>=0; i--){
            auto c = s[i];
            if (c == '*'){
                length += 1;
            }
            else if (c == '#'){
                if (k >= length/2){
                    k = k-length/2;
                }
                length /= 2;
            }
            else if (c == '%'){
                k = length-k-1;
            }
            else{
                if (k == length-1){
                    return c;
                }
                else{
                    length -= 1;
                }
            }
        }
        return '.';
    }
};

int main(){
    Solution sl;
    string s = "a#b%*";
    int k = 1;
    cout << sl.processStr(s, k) << endl;
}
