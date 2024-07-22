#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
static void print_grid_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid1[i][j]);
        }

        printf(" %c ", (i == 1 ? '+' : ' '));

        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid2[i][j]);
        }
        printf("\n");
    }
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First 3x3 grid (updated to stable state)
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    int tmp_grid[3][3];

    // Add grid2 to grid1
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Topple until stable
    while (!is_stable(grid1))
    {
        printf("=\n");
        print_grid(grid1);
        topple(grid1, tmp_grid);
    }
}

/**
 * is_stable - Checks if a sandpile is stable
 * @grid: 3x3 grid to check
 * Returns: 1 if stable, 0 if unstable
 */
static int is_stable(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] >= 4)
                return 0; // Unstable
        }
    }

    return 1; // Stable
}

/**
 * topple - Perform toppling operation on a sandpile
 * @grid: 3x3 grid to topple
 * @tmp_grid: Temporary grid for toppling calculations
 */
static void topple(int grid[3][3], int tmp_grid[3][3])
{
    int i, j;

    // Copy grid to tmp_grid
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            tmp_grid[i][j] = grid[i][j];
        }
    }

    // Perform toppling
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (tmp_grid[i][j] >= 4)
            {
                grid[i][j] -= 4;
                if (i > 0) grid[i-1][j] += 1; // Top neighbor
                if (i < 2) grid[i+1][j] += 1; // Bottom neighbor
                if (j > 0) grid[i][j-1] += 1; // Left neighbor
                if (j < 2) grid[i][j+1] += 1; // Right neighbor
            }
        }
    }
}
