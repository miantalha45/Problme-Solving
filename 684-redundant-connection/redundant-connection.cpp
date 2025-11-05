class Solution {
public:
    bool DFS(unordered_map<int, vector<int>>& list, vector<bool>& visited,
             int parent, int node) {

        visited[node] = true;

        for (auto& n : list[node]) {

            if (n == parent)
                continue;

            if (visited[n]) {
                return true;
            }

            if (DFS(list, visited, node, n)) {
                return true;
            }
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> list;

        for (int i = 0; i < edges.size(); i++) {
            vector<bool> visited(edges.size(), false);
            int u = edges[i][0];
            int v = edges[i][1];

            list[u].push_back(v);
            list[v].push_back(u);

            if (DFS(list, visited, -1, u)) {
                return edges[i];
            }
        }

        return {};
    }
};