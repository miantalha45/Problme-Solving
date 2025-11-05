class Solution {
public:
    unordered_set<int> visited;
    unordered_set<int> inPath;

    bool dfs(unordered_map<int, vector<int>>& list, int node) {

        if (inPath.count(node) > 0) {
            return false;
        }

        visited.insert(node);
        inPath.insert(node);

        for (auto& n : list[node]) {
            if (inPath.count(n) > 0) {
                return false;
            }
            if (visited.count(n) == 0) {
                if (!dfs(list, n)) {
                    return false;
                }
            }
        }

        inPath.erase(node);

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

        unordered_map<int, vector<int>> list;

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            list[v].push_back(u);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited.count(i) == 0) {
                if (!dfs(list, i)) {
                    return false;
                }
            }
        }
        return true;
    }
};