#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s = "a";
        int indx = 0;
        while (indx < n-1){
            if (lcp[indx][indx+1] == 0){
                bool flag = false;
                vector<int> canWrite(26, 1);
                for (int i=0; i<=indx; i++){
                    if (lcp[i][indx+1] > 0){
                        s.push_back(s[i]);
                        flag = true;
                        break;
                    }
                    else{
                        canWrite[s[i]-'a'] = 0;
                    }
                }
                if (flag){
                    indx++;
                }
                else{
                    for (int i=0; i<26; i++){
                        if (canWrite[i]){
                            s.push_back('a'+i);
                            flag = true;
                            break;
                        }
                    }
                    if (flag){
                        indx++;
                    }
                    else{
                        return "";
                    }
                }
            }
            else{
                // lcp[indx][indx+1] > 0
                int length = lcp[indx][indx+1];
                s += string(length, s[indx]);
                indx += length;
            }
        }

        if (s.size() != n){
            return "";
        }

        vector<vector<int>> newLcp(n+1, vector<int>(n+1, 0));
        for (int i=n-1; i>=0; i--){
            for (int j=n-1; j>=0; j--){
                if (s[i] == s[j]){
                    newLcp[i][j] = max(newLcp[i][j], newLcp[i+1][j+1]+1);
                }
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (newLcp[i][j] != lcp[i][j]){
                    return "";
                }
            }
        }
        return s;
    }
};

int main(){
    Solution s;
    vector<vector<int>> lcp = {{4,0,2,0},{0,3,0,1},{2,0,2,0},{0,1,0,1}};
    cout << s.findTheString(lcp) << endl;
}
