/*
holy G's, a sudoku solver...
what do solvers remind me of?
generally some convoluted backtracking approach
yeah, got it instantly, hell yeah. Giving myself the opportunity to check the
editorial.
*/
#include <vector>
using namespace std;

class Solution
{
private:
    int box_size = 3;
    int grid_size = 9;
    int **rows;
    int **cols;
    int **boxes;
    vector<vector<char>> board;
    bool solved = false;

    bool can_place(int d, int row, int col)
    {
        int box = (row / box_size) * box_size + col / box_size;
        return rows[row][d] + cols[col][d] + boxes[box][d] == 0;
    }

    void place_number(int d, int row, int col)
    {
        int box = (row / box_size) * box_size +
                  col / box_size; // do not fear integer division
        rows[row][d]++;
        cols[col][d]++;
        boxes[box][d]++;
        board[row][col] =
            (char)(d +
                   '0'); // put the equivalent char, check problem description
    }

    void remove_number(int d, int row, int col)
    {
        int box = (row / box_size) * box_size + col / box_size;
        rows[row][d]--;
        cols[col][d]--;
        boxes[box][d]--;
        board[row][col] = '.';
    }

    void place_next_numbers(int row, int col)
    {
        if ((col == grid_size - 1) && (row == grid_size - 1))
        {
            solved = true;
        }
        else
        {
            if (col == grid_size - 1)
            {
                backtrack(row + 1, 0);
            }
            else
            {
                backtrack(row, col + 1);
            }
        }
    }

    void backtrack(int row, int col)
    {
        if (board[row][col] == '.')
        {
            for (int d = 1; d < 10; d++)
            {
                if (can_place(d, row, col))
                {
                    place_number(d, row, col);
                    place_next_numbers(row, col);
                    if (!solved)
                    {
                        remove_number(d, row, col);
                    }
                }
            }
        }
        else
        {
            place_next_numbers(row, col);
        }
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        this->board = board;
        rows = new int *[grid_size];
        cols = new int *[grid_size];
        boxes = new int *[grid_size]; // this feels wrong
        for (int i = 0; i < grid_size; i++)
        {
            rows[i] = new int[grid_size + 1]();
            cols[i] = new int[grid_size + 1]();
            boxes[i] = new int[grid_size + 1]();
        }
        for (int i = 0; i < grid_size; i++)
        {
            for (int j = 0; j < grid_size; j++)
            {
                char num = board[i][j];
                if (num != '.')
                {
                    int d = num - '0'; // esoteric
                    place_number(d, i, j);
                }
            }
        }
        backtrack(0, 0);
        board = this->board;
    }
};