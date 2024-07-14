class Solution {
    final int[] dX = {1, 0, -1, 0};
    final int[] dY = {0, 1, 0, -1};
    public int orangesRotting(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int step = 0;
        int freshLeft = numFresh(grid);

        if (freshLeft == 0)
            return 0;

        // load frontier 
        ArrayDeque<Integer> frontier = new ArrayDeque<Integer>();
        boolean[][] visited = new boolean[rows][cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        if (i + dY[k] >= rows || i + dY[k] < 0 || j + dX[k] >= cols ||
                            j + dX[k] < 0 || grid[i + dY[k]][j + dX[k]] != 1 ||
                            visited[i + dY[k]][j + dX[k]])
                            continue;
                        visited[i + dY[k]][j + dX[k]] = true;
                        freshLeft--;                   
                        frontier.add((i + dY[k]) * cols + j + dX[k]);
                    }
                }
            }
        }
        if (frontier.isEmpty())
        {   
            return -1;
        }
        
        // conduct BFS
        while (!frontier.isEmpty())
        {
            step++;
            ArrayDeque<Integer> newFrontier = new ArrayDeque<Integer>();
            while (!frontier.isEmpty())
            {
                int position = frontier.poll();
                int i = position / cols;
                int j = position % cols;
                    for (int k = 0; k < 4; k++)
                    {
                        if (i + dY[k] >= rows || i + dY[k] < 0 || j + dX[k] >= cols ||
                            j + dX[k] < 0 || grid[i + dY[k]][j + dX[k]] != 1 || 
                            visited[i + dY[k]][j + dX[k]])
                            continue;
                        visited[i + dY[k]][j + dX[k]] = true;
                        freshLeft--;
                        newFrontier.add((i + dY[k]) * cols + j + dX[k]);
                    }
            }
            frontier = newFrontier;

        }

        if (freshLeft != 0)
            return -1;
        
        return step;
    }

    int numFresh (int[][] grid)
    {
        int total = 0;
        for (int[] row : grid)
        {
            for (int orange : row)
            {
                if (orange == 1)
                    total++;
            }
        }
        return total;
    }
}