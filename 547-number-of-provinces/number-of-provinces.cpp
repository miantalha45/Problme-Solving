class Solution {
public:

    void DFS(vector<bool>& visited, unordered_map<int, vector<int>>& list, int node) {
        visited[node] = true;
        for(auto n : list[node]) {
            if(!visited[n]) {
                DFS(visited, list, n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        unordered_map<int, vector<int>> list;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && isConnected[i][j] == 1)
                    list[i].push_back(j);
            }
        }

        vector<bool> visited(n, false);

        int count = 0;
        for(int i = 0;i < n;  i++) {
            if(!visited[i]) {
                DFS(visited, list, i);
                count++;
            }
        }

        return count;
    }
};