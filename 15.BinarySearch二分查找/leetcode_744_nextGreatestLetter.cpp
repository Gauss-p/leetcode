#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n-1;
        while (l<=r){
            int mid = (l+r)/2;
            if (letters[mid] > target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return letters[l%n];
    }
};

int main(){
    Solution s;
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';
    cout << s.nextGreatestLetter(letters, target) << endl;
}
