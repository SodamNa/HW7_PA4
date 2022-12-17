class Solution
{
public:
    int numIslands(vector<vector<char> >& grid)
    {
        if (0 == grid.size() || 0 == grid[0].size()) // If grid is empty 
            return 0; // end the function. 

        int num = 0; // To assign number of islands. 
        for (int i = 0; i < grid.size(); i++) { //
            for (int j = 0; j < grid[0].size(); j++) {
                if ('1' == grid[i][j]) { // If the element of grid is '1', it means an existence of island.
                    num++; Add 1 to num.
                    dfs(grid, i, j); To search the island(other '1' followed bt this element), execute dfs function.
                }
            }
        }
        return num;
    }
    
private:
    void dfs(vector<vector<char> >& grid, int i, int j)
    {
        if (0 > i || i >= grid.size() || 0 > j || j >= grid[0].size() || '0' == grid[i][j])
            return; // End the recursion

        grid[i][j] = '0'; // To avoid duplication, mark the searched element as '0'
        vector<int> dir({-1, 0, 1, 0, -1}); 
        // int nums[] = {-1, 0, 1, 0, -1};
        // vector<int> dir(nums, nums + sizeof(nums) / sizeof(int));
        for (int idx = 0; idx < dir.size() - 1; idx++) {
            int rowIdx = i + dir[idx]; 
            int colIdx = j + dir[idx + 1];
            dfs(grid, rowIdx, colIdx);
        }
    }
};
