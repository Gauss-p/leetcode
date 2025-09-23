#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    int myInt(string s){
        int ans = 0;
        for (auto& c : s){
            ans = ans*10+(c-'0');
        }
        return ans;
    }
public:
    int compareVersion(string version1, string version2) {
        version1 += '.';
        version2 += '.';
        int n1 = version1.size(), n2 = version2.size();
        vector<int> v1, v2;
        int last1 = 0, last2 = 0;
        for (int i=0; i<n1; i++){
            if (version1[i] == '.'){
                v1.push_back(myInt(version1.substr(last1, i-last1)));
                last1 = i+1;
            }
        }
        for (int i=0; i<n2; i++){
            if (version2[i] == '.'){
                v2.push_back(myInt(version2.substr(last2, i-last2)));
                last2 = i+1;
            }
        }
        for (int i=0; i<max(n1, n2); i++){
            int cur1 = 0;
            if (i < v1.size()){
                cur1 = v1[i];
            }
            int cur2 = 0;
            if (i < v2.size()){
                cur2 = v2[i];
            }
            if (cur1 < cur2){
                return -1;
            }
            if (cur1 > cur2){
                return 1;
            }
        }
        return 0;
    }
};

int main(){
    Solution s;
    string version1 = "1.2", version2 = "1.10";
    cout << s.compareVersion(version1, version2) << endl;
}
