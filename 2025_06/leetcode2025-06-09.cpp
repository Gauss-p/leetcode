#include <iostream>
using namespace std;

class Solution {
private:
    int MAX_VALUE;
    int cnt_subTree_size(int x){
        int size = 0;
        long long l = x, r = x+1;
        while (l<=MAX_VALUE){
            size += min(r, 1ll*MAX_VALUE+1)-l;
            l *= 10;
            r *= 10;
        }
        return size;
    }
public:
    int findKthNumber(int n, int k) {
        MAX_VALUE = n;
        int cur_node = 1;
        k -= 1;
        while (k > 0){
            int cur_size = cnt_subTree_size(cur_node);
            if (cur_size-1 < k){
                k -= cur_size;
                cur_node += 1;
            }
            else{
                k -= 1;
                cur_node *= 10;
            }
        }
        return cur_node;
    }
};

int main(){
    Solution s;
    int n = 13, k = 2;
    cout << s.findKthNumber(n, k) << endl;
    return 0;
}
