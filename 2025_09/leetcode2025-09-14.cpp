#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
    string exchange_vowels(string w){
        string s;
        for (auto& c : w){
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                s += '*';
            }
            else{
                s += c;
            }
        }
        return s;
    }

    string lower(string w){
        string s;
        for (auto& c : w){
            if (c >= 'A' && c<='Z'){
                s += ('a'+(c-'A'));
            }
            else{
                s += c;
            }
        }
        return s;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n = wordlist.size();
        unordered_set<string> wordSet(wordlist.begin(), wordlist.end());
        unordered_map<string, int> lowercase;
        unordered_map<string, int> vowel;
        for (int i=n-1; i>=0; i--){
            string cur = lower(wordlist[i]);
            lowercase[cur] = i;
            vowel[exchange_vowels(cur)] = i;
        }

        for (int i=0; i<queries.size(); i++){
            if (wordSet.count(queries[i])){
                continue;
            }
            string cur = lower(queries[i]);
            if (lowercase.count(cur)){
                queries[i] = wordlist[lowercase[cur]];
            }
            else if (vowel.count(exchange_vowels(cur))){
                queries[i] = wordlist[vowel[exchange_vowels(cur)]];
            }
            else{
                queries[i] = "";
            }
        }
        return queries;
    }
};

int main(){
    Solution s;
    vector<string> wordlist = {"KiTe","kite","hare","Hare"};
    vector<string> queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
    vector<string> res = s.spellchecker(wordlist, queries);
    for (auto& s : res){
        cout << s << " ";
    }
    cout << endl;
}
