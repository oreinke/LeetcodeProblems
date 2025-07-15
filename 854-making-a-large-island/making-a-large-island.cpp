class Solution {
public:
    int dfs (int i, int j, pair<int, int> parent, vector<vector<int>> &grid, vector<vector<bool>> &visited, vector<vector<pair<int, int>>> &parents) {
        if (grid[i][j] == 0 || visited[i][j]) return 0;
        visited[i][j] = true;
        parents[i][j] = parent;
        int cnt = 1;
        if (i != 0) {
            cnt += dfs(i - 1, j, parent, grid, visited, parents);
        }
        if (i != grid.size() - 1) {
            cnt += dfs(i + 1, j, parent, grid, visited, parents);
        }
        if (j != 0) {
            cnt += dfs(i, j - 1, parent, grid, visited, parents);
        }
        if (j != grid.size() - 1) {
            cnt += dfs(i, j + 1, parent, grid, visited, parents);
        }
        return cnt;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited (n, vector<bool> (n, false));
        vector<vector<pair<int, int>>> parents (n, vector<pair<int, int>> (n, {-1, -1}));
        map<pair<int, int>, int> island;
        int best = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int res = dfs(i, j, {i, j}, grid, visited, parents);
                    island[{i, j}] = res;
                    best = max(best, res);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int val = 1;
                    set<pair<int, int>> checked;
                    if (i != 0) {
                        val += island[parents[i - 1][j]];
                        checked.insert(parents[i - 1][j]);
                    }
                    if (i != n - 1 && !checked.contains(parents[i + 1][j])) {
                        val += island[parents[i + 1][j]];
                        checked.insert(parents[i + 1][j]);
                    }

                    if (j != 0 && !checked.contains(parents[i][j - 1])) {
                        val += island[parents[i][j - 1]];
                        checked.insert(parents[i][j - 1]);
                    }
                    if (j != n - 1 && !checked.contains(parents[i][j + 1])) {
                        val += island[parents[i][j + 1]];
                    }
                    best = max(best, val);
                }
            }
        }
        return best;
    }
};