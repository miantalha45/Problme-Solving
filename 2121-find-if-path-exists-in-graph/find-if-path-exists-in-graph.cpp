class Solution {
public:
    unordered_set<int> visited;

    bool DFS(unordered_map<int, vector<int>>& list, int node, int destination) {
        if (visited.count(node))
            return false;
        visited.insert(node);
        if (node == destination)
            return true;

        for (auto n : list[node]) {
            if (DFS(list, n, destination)) {
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {

        unordered_map<int, vector<int>> list;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            list[u].push_back(v);
            list[v].push_back(u);
        }

        return DFS(list, source, destination);
    }
};