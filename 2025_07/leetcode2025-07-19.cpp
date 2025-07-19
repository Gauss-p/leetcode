#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res = {folder[0]};
        for (int i=1; i<folder.size(); i++){
            string cur = folder[i], last = res[res.size()-1];
            int m = last.size(), n = cur.size();
            if (m>=n || !(last==cur.substr(0, m) && cur[m]=='/')){
                res.push_back(cur);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> folder = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    vector<string> res = s.removeSubfolders(folder);
    for (auto&i : res){
        cout << i << " ";
    }
    cout << endl;
}
