class Solution
{
public:
    int numIslands(vector<vector<char> >& grid)
    {
        if (0 == grid.size() || 0 == grid[0].size()) // If grid is empty 
            return 0; // end the function. 

        int num = 0; // To assign number of islands. 
        for (int i = 0; i < grid.size(); i++) { // Execute until the end of grid.
            for (int j = 0; j < grid[0].size(); j++) { // Depth fisrt
                if ('1' == grid[i][j]) { // If the element of grid is '1', it means an existence of island.
                    num++; // Add 1 to num.
                    dfs(grid, i, j); // To search the island(other '1' followed bt this element), execute dfs function.
                }
            }
        }
        return num; // Return the number of islands.
    }
    
private:
    void dfs(vector<vector<char> >& grid, int i, int j)
    {
        if (0 > i || i >= grid.size() || 0 > j || j >= grid[0].size() || '0' == grid[i][j])
            return; // End the recursion

        grid[i][j] = '0'; // To avoid duplication, mark the searched element as '0'
        vector<int> dir({-1, 0, 1, 0, -1}); // Direction to search surroundings 
        for (int index = 0; index < dir.size() - 1; index++) { // Repeat until all surroundings are searched whether they are '0' or not
            int rowIdx = i + dir[index]; // Move to near on the same row
            int colIdx = j + dir[index + 1]; // Move to near on the same column
            dfs(grid, rowIdx, colIdx); // Excute the recursion until the surroundings are all '0'
        }
    }
};
