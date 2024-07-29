class Solution {
private:
    vector<vector<int>> neibor; // �洢ÿ��Ԫ�ص��ھ�
public:
    int calc(int indx, vector<vector<int>> graph, int n, set<int> itl){
        // �ú������������indx����ͨ���У����ɾ��n�Žڵ㣬��ô�ܹ�����ȡ����ٸ�����
        // ˼·�Ǵ�n��ʼbfs��һȦһȦѰ�ң������һ����������һ���Ѹ�Ⱦ�ڵ㣬����ֹ������·���ϵ�����
        // �����������n��ʼ��������һ��δ��Ⱦ�ڵ�x��·����������һ���Ѹ�Ⱦ�ڵ㣬����ɾ����n��x���ջ��ǻ��Ⱦ
        vector<int> q;
        q.push_back(n);
        int cnt = 0;
        vector<int> visited(graph.size(), 0); // ��ֹ����ѭ��
        while (q.size()){
            vector<int> q2;
            for (int i : q){
                for (int j : neibor[i]){
                    if (itl.count(j) == 0 && visited[j] == 0){
                        // ���jû�б���Ⱦ������·���ſ��Լ�������ȥ
                        // ͬʱj����û�б����ʹ�����ֹѭ��
                        visited[j] = 1;
                        cnt++;
                        q2.push_back(j);
                    }
                }
            }
            q = q2;
        }
        return cnt;
    }
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<int> sizes; // �洢ÿ����ͨ��Ĵ�С
        vector<vector<int>> vvi; // �洢ÿ����ͨ���б���Ⱦ�ĵ���
        neibor.resize(n);
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (graph[i][j] == 1 && i != j){
                    neibor[i].push_back(j); // ���������ͬ�ĵ�֮���бߣ��ʹ���neibor��
                }
            }
        }
        set<int> itl(initial.begin(), initial.end()); // ��������initialת����set������������
        // nums�����洢���е�Ԫ�أ��ڲ���ÿһ����ͨ��ʱ��������ͨ��Ľڵ�����нڵ���ɾ��
        // ���Ƿ������Ǽ����Ҳ�ͬ����ͨ��
        vector<int> nums;
        for (int i=0; i<n; i++){
            nums.push_back(i);
        }
        vector<int> visited(n, 0); // ����ж��Ƿ���ʹ���������������ֹ���ֻ�·��������ѭ����
        function<void(int, int, int)> dfs = [&](int x, int fa, int indx){
            sizes[indx]++; // ��ͨ��Ĵ�С����1
            if (itl.count(x)) vvi[indx].push_back(x); // �����ǰ�ڵ㱻��Ⱦ������vvi[indx]��
            nums.erase(remove(nums.begin(), nums.end(), x), nums.end()); // ��nums��ɾ����ǰ�ڵ�
            visited[x] = 1; // ���Ϊ�ѷ���
            for (int y : neibor[x]){
                if (!visited[y] && y != fa){
                    // ���û�з��ʹ������븸�ײ���ͬ���ſ��Լ�������
                    dfs(y, x, indx);
                }
            }
        };

        int indx = -1;
        // �����ѭ���������������е���ͨ���
        while (nums.size()){
            indx++;
            sizes.resize(indx+2);
            vvi.resize(indx+2);
            dfs(nums[0], -1, indx);
        }
        // ����Ҫ��֤���������и�Ⱦ������������սڵ�������M(initial)��С
        // ��Σ�����ж���ڵ����㣺ɾ�����ܹ������Ľڵ�ͬ���࣬��ô�ͷ�����������Сֵ
        // �����������һ����ͨ����ֻ��һ�����Ը�Ⱦ����ô�����Ѹ�Ⱦ�ĵ�����������С��һ������
        int max_num = 0, res = -1;
        for (int i=0; i<=indx; i++){
            if (vvi[i].size() == 1){
                if (sizes[i] > max_num){
                    max_num = sizes[i];
                    res = vvi[i][0];
                }
                if (sizes[i] == max_num){
                    res = min(res, vvi[i][0]);
                }
            }
            if (vvi[i].size() > 1){
                for (int j : vvi[i]){
                    int tmp = calc(i, graph, j, itl);
                    if (tmp > max_num){
                        max_num = tmp;
                        res = j;
                    }
                    if (tmp == max_num){
                        res = min(res, j);
                    }
                }
            }
        }
        return res == -1 ? *min_element(initial.begin(), initial.end()) : res;
    }
};
