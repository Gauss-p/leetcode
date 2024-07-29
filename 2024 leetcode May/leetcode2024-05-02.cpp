#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> heap;
        int n = quality.size();
        for (int i=0; i<n; i++){
            // float w = wage[i], q = quality[i];
            heap.push_back(make_pair(1.0*wage[i]/quality[i], quality[i]));
            // ÿһ�δ洢�����������ı�ֵ������ֻҪ֪������֮�;Ϳ���֪����Ǯ��
            // cout << wage[i] << " " << quality[i] << " " << 1.0*wage[i]/quality[i] << endl;
        }
        sort(heap.begin(), heap.end());
        double res = 1e9;
        priority_queue<int> q;
        // sum�����洢����֮�ͣ�q������������
        int sum = 0;
        for (int i=0; i<n; i++){
            q.emplace(heap[i].second);
            sum += heap[i].second;
            if (q.size() == k){
                // double tmp_sum = 0;
                // auto tmp = sum;
                // for (int j=0; j<k; j++){
                //     tmp_sum += tmp.top();
                //     tmp.pop();
                // }
                res = min(res, sum*heap[i].first); // ÿһ�μ�����Сֵ
                sum -= q.top();
                q.pop();
                // cout << tmp_sum << " " << heap.top().first << endl;
            }
            // heap.pop();
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> quality = {10,20,5}, wage = {70,50,30};
    int k = 2;
    cout << s.mincostToHireWorkers(quality, wage, k) << endl;
}
