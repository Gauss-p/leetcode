#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        vector<set<int>> visited(2);
        for (int i=0; i<n+1; i++){
            visited[i&1].insert(i);
        }
        visited[0].insert(n+1);
        visited[1].insert(n+1);
        
        int start = count(s.begin(), s.end(), '0');
        visited[start&1].erase(start);
        vector<int> q = {start};
        int res = 0;
        while (!q.empty()){
            vector<int> cur;
            for (int z : q){
                if (z == 0){
                    return res;
                }
                int mn = z+k-2*min(k, z);
                int mx = z+k-2*max(0, k-(n-z));

                auto& stl = visited[mn&1];
                auto indx = stl.lower_bound(mn);
                while (indx != stl.end() && *indx <= mx){
                    cur.push_back(*indx);
                    indx = stl.erase(indx);
                }
            }
            q = move(cur);
            res++;
        }
        return -1;
    }
};

int main(){
    Solution sl;
    string s = "110";
    int k = 1;
    cout << sl.minOperations(s, k) << endl;
}
