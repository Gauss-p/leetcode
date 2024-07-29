#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int scoreOfString(string s) {
        int res = 0;
        int n = s.size();
        for (int i=1; i<n; i++){
            res += abs(s[i]-s[i-1]);
        }
        return res;
    }
};

class Solution2 {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        set<int> s;
        for (auto &i : points){
            s.insert(i[0]);
        }
        vector<int> v(s.begin(), s.end());
        sort(v.begin(), v.end());
        int res = 0;
        int begin = v[0];
        for (int &i : v){
            if (i > begin+w){
                res++;
                begin = i;
            }
        }
        res++;
        return res;
    }
};

int main(){
    Solution1 s1;
    string s = "hello";
    cout << s1.scoreOfString(s) << endl;
    // -----------------------------------------------------------------
    Solution2 s2;
    vector<vector<int>> points = {{2,3},{1,2}};
    int w = 0;
    cout << s2.minRectanglesToCoverPoints(points, w) << endl;
}
