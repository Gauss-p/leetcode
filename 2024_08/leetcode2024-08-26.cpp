#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    bool is_pair(int a, int b){
        // 两个数字近似相等的特征就是有且仅有两个位置的数字不同，并且它们位置相反，利用这个特征，当找到第一处不同时，记录下来，当找到第二处不同时，如果顺序相反并且剩余的数字都相同，就一定近似相等
        if (a == b){
            return true;
        }
        if (a < b){
            swap(a, b);
        }
        vector<int> sub;
        while (a > 0){
            int a1 = a%10, b1 = b%10;
            if (a1 == b1){
                a /= 10;
                b /= 10;
                continue;
            }
            if (sub.size() == 0){
                sub.push_back(a1);
                sub.push_back(b1);
                a /= 10;
                b /= 10;
                continue;
            }
            if (a1 == sub[1] && b1 == sub[0] && a/10 == b/10){
                return true;
            }
            return false;
        }
        return false;
    }
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                if (is_pair(nums[i], nums[j])){
                    res++;
                }
            }
        }
        return res;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, int> values;
        unordered_map<int, vector<int>> under;
        for (auto e : employees){
            int id = e->id, val = e->importance;
            vector<int> sub = e->subordinates;
            values[id] = val;
            under[id] = sub;
        }
        queue<int> q;
        q.push(id);
        int res = 0;
        while (!q.empty()){
            int a = q.front();
            res += values[a];
            q.pop();
            for (auto i : under[a]){
                q.push(i);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    Employee* a = new Employee();
    a->id = 1;
    a->importance = 2;
    a->subordinates = {5};
    Employee* b = new Employee();
    b->id = 5;
    b->importance = -3;
    b->subordinates = {};
    vector<Employee*> employees = {a, b};
    int id = 1;
    cout << s.getImportance(employees, id) << endl;
    // ----------------------------------------------------
    vector<int> nums = {3,12,30,17,21};
    cout << s.countPairs(nums) << endl;
}
