class Solution {
public:
    bool dfs (int x, int y, vector<vector<char>>& grid) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return false;;
        if (grid[x][y] == '0') return false;
        grid[x][y] = '0';
        dfs(x - 1, y, grid);
        dfs(x, y - 1, grid);
        dfs(x, y + 1, grid);
        dfs(x + 1, y, grid);
        
        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (dfs(i, j, grid)) cnt++;
            }
        }

        return cnt;
    }
};