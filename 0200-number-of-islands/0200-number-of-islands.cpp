class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // last boundary ar jo water area aaialble h ushko traverse krne ke lie

        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') 
            return;
        // jha visit kr lia h ushko zero consider
        grid[i][j] = '0';
        // all directons ke lie 
        dfs(grid, i - 1, j); // up
        dfs(grid, i + 1, j); // down
        dfs(grid, i, j - 1); // left
        dfs(grid, i, j + 1); // right
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;   
        int count = 0;  
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') { //agar island found then return 1
                    count++;
                    dfs(grid, i, j); // mlum chlega ya mark krega ki har jgah island ka visited ha
                }
            }
        }     
        return count;
    }
};
