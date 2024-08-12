#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MagicDictionary {
private:
    vector<string> dic;
public:
    MagicDictionary() {

    }
    
    int difference(string s1, string s2){
        if (s1.size() != s2.size()){
            return 0;
        }
        int cnt = 0;
        for (int i=0; i<s1.size(); i++){
            if (s1[i] != s2[i]){
                cnt++;
            }
        }
        return cnt;
    }

    void buildDict(vector<string> dictionary) {
        dic = dictionary;
    }
    
    bool search(string searchWord) {
        for (auto s : dic){
            if (difference(s, searchWord) == 1){
                return true;
            }
        }
        return false;
    }
};

int main(){
    MagicDictionary md;
    md.buildDict({"hello", "leetcode"});
    cout << md.search("hello") << endl;
    cout << md.search("hhllo") << endl;
    cout << md.search("hell") << endl;
    cout << md.search("leetcoded") << endl;
}
