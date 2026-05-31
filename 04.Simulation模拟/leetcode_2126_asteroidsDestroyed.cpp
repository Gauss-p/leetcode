#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long cur = mass;
        for (int i=0; i<asteroids.size(); i++){
            if (cur < asteroids[i]){
                return false;
            }
            cur += asteroids[i];
        }
        return true;
    }
};

int main(){
    Solution s;
    int mass = 10;
    vector<int> asteroids = {3,9,19,5,21};
    cout << s.asteroidsDestroyed(mass, asteroids) << endl;
}
