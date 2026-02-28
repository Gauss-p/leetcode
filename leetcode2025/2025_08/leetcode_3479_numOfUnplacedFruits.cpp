#include <iostream>
#include <vector>
using namespace std;

class SegmentTree{
private:
    vector<int> seg;

    void maintain(int o){
        seg[o] = max(seg[2*o], seg[2*o+1]);
    }

    void build(vector<int>& c, int o, int l, int r){
        if (l == r){
            seg[o] = c[l];
            return;
        }
        int mid = (l+r)/2;
        build(c, 2*o, l, mid);
        build(c, 2*o+1, mid+1, r);
        maintain(o);
    }

public:
    SegmentTree(vector<int>& c){
        int n = c.size();
        // size_t n = c.size();
        int size = 2;
        if (n > 1){
            size = 2<<(32-__builtin_clz(n-1));
        }
        seg.resize(size, 0);
        build(c, 1, 0, n-1);
    }

    
    int find_first_and_update(int o, int l, int r, int x){
        if (seg[o] < x){
            return -1;
        }
        if (l == r){
            seg[o] = -1;
            return l;
        }
        int mid = (l+r)/2;
        int i = find_first_and_update(2*o, l, mid, x);
        if (i<0){
            i = find_first_and_update(2*o+1, mid+1, r, x);
        }
        maintain(o);
        return i;
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree segT(baskets);
        int n = baskets.size();
        int res = fruits.size();
        for (int x : fruits){
            if (segT.find_first_and_update(1, 0, n-1, x) >= 0){
                res--;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> fruits = {4,2,5};
    vector<int> baskets = {3,5,4};
    cout << s.numOfUnplacedFruits(fruits, baskets) << endl;
}
