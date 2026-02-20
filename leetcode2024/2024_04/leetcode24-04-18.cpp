class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // if (changed.size() % 2 != 0) return {};
        // sort(changed.begin(), changed.end());
        // multiset<int> chged(changed.begin(), changed.end());
        // vector<int> res;
        // for (int i : changed){
        //     if (chged.count(i) == 0) continue;
        //     if (chged.count(i*2)){
        //         res.push_back(i);
        //         auto it1 = chged.find(i);
        //         if (it1 != chged.end()){
        //             chged.erase(it1);
        //         }
        //         auto it2 = chged.find(i*2);
        //         if (it2 != chged.end()){
        //             chged.erase(it2);
        //         }
        //         continue;
        //     }
        //     else{
        //         return {};
        //     }
        // }
        // return res;
        if (changed.size() % 2 != 0) return {};
        sort(changed.begin(), changed.end());
        unordered_map<int, int> dic;
        for (int i : changed){
            dic[i]++;
        }
        vector<int> res;
        for (int i : changed){
            if (dic[i] == 0){
                continue;
            }
            if (dic[i*2] == 0){
                return {};
            }
            if (dic[i*2] != 0){
                dic[i]--;
                dic[i*2]--;
                res.push_back(i);
            }
        }
        return res;
    }
};
