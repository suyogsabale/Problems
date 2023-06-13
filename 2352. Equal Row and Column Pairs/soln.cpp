class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &grid)
    {
        int i, j;
        vector<vector<int>> b(grid.size(), vector<int>(grid[0].size()));
        for (i = 0; i < grid.size(); i++)
            for (j = 0; j < grid[0].size(); j++)
                b[i][j] = grid[j][i];

        return b;
    }

    int equalPairs(vector<vector<int>> &grid)
    {
        map<vector<int>, int> mp, mpcol;
        int count = 0;

        // row
        for (int i = 0; i < grid.size(); ++i)
        {
            ++mp[grid[i]];
        }

        vector<vector<int>> b = transpose(grid);
        // col
        for (int i = 0; i < b.size(); ++i)
        {
            ++mpcol[b[i]];
        }

      
        set<vector<int>> s;
        for (int i = 0; i < grid.size(); ++i)
        {
            if (s.find(grid[i]) == s.end())
            {
                int a = mp[grid[i]];
                int b = mpcol[grid[i]];
                count += a * b;
            }
            s.insert(grid[i]);
        }
        return count;
    }
};