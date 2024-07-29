#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        vector<int> front_sum(n);
        int tmp_sum = 0;
        for (int i=0; i<n; i++){
            tmp_sum += customers[i];
            front_sum[i] = tmp_sum;
        }
        vector<int> front_customer(n), back_customer(n);
        int ft = 0, bk = 0;
        for (int i=0; i<n; i++){
            ft += customers[i]*(1-grumpy[i]);
            bk += customers[n-i-1]*(1-grumpy[n-i-1]);
            front_customer[i] = ft;
            back_customer[n-i-1] = bk;
        }
        int res = 0;
        for (int i=0; i<=n-minutes; i++){
            int front, back, middle;
            front = i==0 ? 0 : front_customer[i-1];
            back = i+minutes-1 == n-1 ? 0 : back_customer[i+minutes];
            middle = i==0 ? front_sum[minutes-1] : front_sum[i+minutes-1]-front_sum[i-1];
            // cout << front << " " << middle << " " << back << endl;
            res = max(res, front+back+middle);
        }
        return res;
    }
};
