class Solution {
public:
    int n_rows;
    int n_cols;
    int start_row;
    int start_col;
    int goal_row;
    int goal_col;

    int dfs(int r, int c, std::set<std::pair<int, int>>& visited_set, 
            const vector<vector<int>>& grid) {
        if(r<start_row || c<start_col){
            return 0;
        }
        if(r==n_rows || c==n_cols){
            return 0;
        }
        if(visited_set.count(std::pair(r, c))){
            return 0;
        }
        if(grid[r][c]==1){
            return 0;
        }
        if(r==goal_row && c==goal_col){
            return 1;
        }

        int count = 0;

        visited_set.insert(std::pair(r, c));
        count += dfs(r+1, c, visited_set, grid);
        count += dfs(r-1, c, visited_set, grid);
        count += dfs(r, c+1, visited_set, grid);
        count += dfs(r, c-1, visited_set, grid);
        visited_set.erase(std::pair(r, c));

        return count;
    }

    int countPaths(vector<vector<int>>& grid) {
        n_rows = grid.size();
        n_cols = grid[0].size();
        start_row = 0;
        start_col = 0;
        goal_row = n_rows-1;
        goal_col = n_cols-1;
        std::set<std::pair<int, int>> visited_set;
        return dfs(0, 0, visited_set, grid);
    }
};
