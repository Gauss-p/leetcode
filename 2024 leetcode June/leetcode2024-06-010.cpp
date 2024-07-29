#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size(), i=0, j=n-1;
        int res = 0;
        // ǰ��˫ָ������������С���������֮��С�ڵ���limit��������һ����
        // �����������������һ����
        while (i <= j){
            if (people[i]+people[j] <= limit){
                i++;
                j--;
            }
            else{
                j--;
            }
            res++;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> people = {1, 2, 2, 3};
    int limit = 4;
    cout << s.numRescueBoats(people, limit) << endl;
}
