#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TextEditor {
private:
    vector<char> left, right;
public:
    TextEditor() {
    }
    
    void addText(string text) {
        for (char c : text) left.push_back(c);
    }
    
    int deleteText(int k) {
        int res = 0;
        while (k && left.size()>0){
            left.erase(left.end()-1);
            k--;
            res++;
        }
        return res;
    }
    
    string cursorLeft(int k) {
        while (k && left.size()>0){
            char tmp = left[left.size()-1];
            left.erase(left.end()-1);
            right.push_back(tmp);
            k--;
        }
        string res;
        k = 10;
        for (int i=left.size()-1; i>=0&&k>0; i--){
            res = left[i]+res;
            k--;
        }
        return res;
    }
    
    string cursorRight(int k) {
        while (k && right.size()>0){
            char tmp = right[right.size()-1];
            right.erase(right.end()-1);
            left.push_back(tmp);
            k--;
        }
        string res;
        k = 10;
        for (int i=left.size()-1; i>=0&&k>0; i--){
            res = left[i]+res;
            k--;
        }
        return res;
    }
};

int main(){
    TextEditor te;
    vector<string> op = {"addText","deleteText","addText","cursorRight","cursorLeft","deleteText","cursorLeft","cursorRight"};
    vector<string> adds = {"leetcode","practice"};
    vector<int> nums = {4,3,8,10,2,6};
    int a = 0, n = 0;
    for (auto&o : op){
        if (o == "addText"){
            te.addText(adds[a]);
            a++;
        }
        else if (o == "deleteText"){
            cout << te.deleteText(nums[n]) << endl;
            n++;
        }
        else if (o == "cursorRight"){
            cout << te.cursorRight(nums[n]) << endl;
            n++;
        }
        else{
            cout << te.cursorLeft(nums[n]) << endl;
            n++;
        }
    }
}
