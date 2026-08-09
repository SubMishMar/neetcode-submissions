class Solution {
public:
    int bfs(int r, int c, const vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }
        int n_rows = grid.size();
        int n_cols = grid[0].size();
        std::deque<std::pair<int, int>> dq;
        std:: set<std::pair<int, int>> visited;
        dq.push_back(std::pair<int, int>(r, c));
        visited.insert(std::pair<int, int>(r, c));
        int length = 0;
        while (dq.size()>0) {
            int level_size = dq.size();
            for (int i = 0; i < level_size; i++) {
                const auto curr = dq.front();
                dq.pop_front();
                int curr_row = curr.first;
                int curr_col = curr.second;
                if( curr_row==n_rows-1 && curr_col==n_cols-1 ){
                    return length;
                }
                constexpr int kNeighbors{4};
                std::array<std::pair<int, int>, kNeighbors> neighbors;
                neighbors[0] = std::pair<int, int>(curr_row+1, curr_col);
                neighbors[1] = std::pair<int, int>(curr_row-1, curr_col);
                neighbors[2] = std::pair<int, int>(curr_row, curr_col+1);
                neighbors[3] = std::pair<int, int>(curr_row, curr_col-1);
                for(const auto neighbor : neighbors) {
                    int neighbour_r = neighbor.first;
                    int neighbour_c = neighbor.second;
                    if(neighbour_r<0||neighbour_c<0) {
                        continue;
                    }
                    if(neighbour_r==n_rows||neighbour_c==n_cols) {
                        continue;
                    }
                    if(grid[neighbour_r][neighbour_c]==1) {
                        continue;
                    }
                    if(visited.find(neighbor)!=visited.end()) {
                        continue;
                    }
                    dq.push_back(std::pair<int, int>(neighbour_r, neighbour_c));
                    visited.insert(std::pair<int, int>(neighbour_r, neighbour_c));
                }
            }
            length+=1;
        }
        return -1;
    }

    int shortestPath(vector<vector<int>>& grid) {
        return bfs(0, 0, grid);
    }
};
