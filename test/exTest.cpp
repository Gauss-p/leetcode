#include <iostream>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    // for (int i=1; i<10; i++){
        // cout << (i%(-2)) << endl;
    // }
    // cout << "----------" << endl;
    // for (int i=-1; i>-10; i--){
        // cout << i/(-2) << " " << (i%(-2)) << endl;
    // }
    // bitset<64> bs(15);
    // cout << bs << endl;
    // long long res = pow(2, 20);
    // cout << res << endl;
    vector<int> v = {1,1,2,2,4,5,5,6,7777};
    auto up_it = upper_bound(v.begin(), v.end(), 7);
    auto lo_it = lower_bound(v.begin(), v.end(), 7);
    cout << up_it-v.begin() << " " << v[up_it-v.begin()] << endl;
    cout << lo_it-v.begin() << " " << v[lo_it-v.begin()] << endl;
    return 0;
}
