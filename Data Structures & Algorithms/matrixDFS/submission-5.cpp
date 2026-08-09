class Solution {
public:
    int n_rows = 0;
    int n_cols = 0;
    int start_row = 0;
    int start_col = 0;
    int goal_row = 0;
    int goal_col = 0;

    int dfs(int r, int c, std::set<std::pair<int, int>>& visited, const vector<vector<int>>& grid) {
        if (r<0 || c<0) {
            return 0;
        }
        if (r==n_rows || c==n_cols) {
            return 0;
        }
        if (grid[r][c]==1) {
            return 0;
        }
        if (visited.find(std::pair(r, c))!=visited.end()) {
            return 0;
        }
        if (r==goal_row && c==goal_col) {
            return 1;
        }

        visited.insert(std::pair(r, c));

        int count = 0;
        count += dfs(r+1, c, visited, grid);
        count += dfs(r-1, c, visited, grid);
        count += dfs(r, c+1, visited, grid);
        count += dfs(r, c-1, visited, grid);

        visited.erase(std::pair(r, c));

        return count;
    }

    int countPaths(vector<vector<int>>& grid) {
        n_rows = grid.size();
        n_cols = grid[0].size();
        start_row = 0;
        start_col = 0;
        goal_row = n_rows-1;
        goal_col = n_cols-1;
        std::set<std::pair<int, int>> visited;
        return dfs(start_row, start_col, visited, grid);
    }
};
