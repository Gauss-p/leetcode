class SnapshotArray {
private:
    vector<int> cur;
    unordered_map<int, vector<pair<int, int>>> all_element;
    int cur_indx, len;
public:
    SnapshotArray(int length) {
        cur_indx = -1;
        len = length;
        cur.resize(length, 0);
    }
    
    void set(int index, int val) {
        cur[index] = val;
        all_element[index].push_back(make_pair(cur_indx+1, val));
    }
    
    int snap() {
        cur_indx++;
        return cur_indx;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(all_element[index].begin(), all_element[index].end(), make_pair(snap_id+1, -1));
        return it == all_element[index].begin() ? 0 : prev(it)->second;
        // int res = 0;
        // for (auto &i : all_element[index]){
        //     if (i.first <= snap_id){
        //         res = i.second;
        //     }
        // }
        // return res;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
