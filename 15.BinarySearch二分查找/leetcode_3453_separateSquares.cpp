#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> sq;
    bool check(double mid){
        double above = 0, under = 0;
        for (int i=0; i<sq.size(); i++){
            double u = 1.0*sq[i][1], d = 1.0*sq[i][0];
            if (u<=mid){
                under += 1.0*(u-d)*(u-d);
            }
            else if (d>=mid){
                above += 1.0*(u-d)*(u-d);
            }
            else{
                under += 1.0*(mid-d)*(u-d);
                above += 1.0*(u-mid)*(u-d);
            }
        }
        return above <= under;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double l = 0, r = 0;
        for (int i=0; i<squares.size(); i++){
            int x = squares[i][0], y = squares[i][1], l = squares[i][2];
            sq.push_back({y, y+l});
            r = max(r, 1.0*(y+l));
        }
        sort(sq.begin(), sq.end());
        
        while (abs(l-r) > 1e-5){
            double mid = (l+r)/2;
            if (check(mid)){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        return l;
    }
};

int main(){
    Solution s;
    vector<vector<int>> squares = {{0,0,1},{2,2,1}};
    cout << s.separateSquares(squares) << endl;
}
