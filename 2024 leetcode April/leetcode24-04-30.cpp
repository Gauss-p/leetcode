class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int res = 0;
        for (int i : hours){
            if (i >= target){
                res++;
            }
        }
        return res;
    }
};
