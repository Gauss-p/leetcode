#include <iostream>
#include <unordered_map>
using namespace std;

class FrequencyTracker {
private:
    unordered_map<int, int> dic;
    unordered_map<int, int> dic2;
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        dic2[dic[number]]--;
        dic[number]++;
        dic2[dic[number]]++;
    }
    
    void deleteOne(int number) {
        if (dic[number]){
            dic2[dic[number]]--;
            dic[number]--;
            dic2[dic[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        return dic2[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
 
int main(){
    FrequencyTracker* obj = new FrequencyTracker();
    obj->add(1);
    obj->deleteOne(1);
    bool param_3 = obj->hasFrequency(1);
    cout << param_3 << endl;
}
