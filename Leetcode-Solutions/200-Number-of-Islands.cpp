class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    counter++;
                visitUsingDFS(grid, i, j);
                }
            }
        }
        return counter;
    }
    void visitUsingDFS(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        visitUsingDFS(grid, i-1, j);
        visitUsingDFS(grid, i+1, j);
        visitUsingDFS(grid, i, j-1);
        visitUsingDFS(grid, i, j+1);
    }
};