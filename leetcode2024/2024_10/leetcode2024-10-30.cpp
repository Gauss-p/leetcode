#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        for (int i=0; i<n-1; i++){
            int a = s[i]-'0', b = s[i+1]-'0';
            if (a%2 == b%2 && a > b){
                swap(s[i], s[i+1]);
                break;
            }
        }
        return s;
    }
};

int main(){
    Solution so;
    string s = "45320";
    cout << so.getSmallestString(s) << endl;
}
