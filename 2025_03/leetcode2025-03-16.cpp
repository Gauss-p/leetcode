#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        int res = 0;
        for (char a='a'; a<='z'; a++){
            for (char b='a'; b<='z'; b++){
                if (b==a) continue;
                int f0=0, f1=INT_MIN;
                for (int i=0; i<n; i++){
                    char c = s[i];
                    if (c == a){
                        f0 = max(f0, 0)+1;
                        f1 = f1+1;
                    }
                    else if (c == b){
                        f0 = max(f0, 0)-1;
                        f1 = f0;
                    }
                    else{
                        f0 = max(f0, 0);
                        f1 = f1;
                    }
                    res = max(res, f1);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "aababbb";
    cout << sl.largestVariance(s) << endl;
}
