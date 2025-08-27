/*

Brute force spit: we can just try, for each grid position, to start, in four
directions, a longest v-shaped diagonal segment. Each segment can then make at
most one 90 degree turn. So, it's like O(m*n*4*(2^(the diagonal segment starting
at i,j))), which smells quite outlandish. I think there are like repetitive
subproblems, but not exactly. For each position, we can ask, what is the length
of the longest turn-making segment starting here. But also the length of the
longest straight segment starting here. So, probably DP. But two questions. So,
following THE hint, we should pick one of those questions and answer it with DP.
Which question?
- at which point, of this straight segment, is it best to make the turn?
But, I think, as we can make 4 different rotations (not at once, but depending
on our direction), we will need 4 additional matrices. Each position of the
matrix would answer:
- what is the longest esoteric sequence starting here?

*/
using namespace std;

enum class DiagDir { // diagonal direction
    MAIN_UP = 0,
    MAIN_DOWN = 1,
    ANTI_UP = 2,
    ANTI_DOWN = 3,
    COUNT = 4
};

const int NUM_DIRECTIONS = static_cast<int>(DiagDir::COUNT);

class Solution {
public:
    int gen_v_diag(int row, int col, DiagDir dir, bool has_turned,
                   int preceding_val, const vector<vector<int>>& grid,
                   vector<vector<vector<vector<int>>>>& dp) {
        // base cases
        // boundary conditions
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            return 0;
        }

        // alternating path criteria
        if (preceding_val == -1 && grid[row][col] != 1) {
            return 0;
        }
        if (preceding_val == 1 && grid[row][col] != 2) {
            return 0;
        }
        if (preceding_val == 0 && grid[row][col] != 2) {
            return 0;
        }
        if (preceding_val == 2 && grid[row][col] != 0) {
            return 0;
        }

        // memo check
        if (dp[row][col][static_cast<int>(dir)][has_turned] != -1) {
            return dp[row][col][static_cast<int>(dir)][has_turned];
        }

        // next step
        int next_row, next_col;
        int next_row_clock, next_col_clock;
        int next_row_counter, next_col_counter;
        DiagDir new_dir_clock, new_dir_counterclock;
        switch (dir) {
        case DiagDir::MAIN_UP:
            next_row = row - 1;
            next_col = col - 1;

            new_dir_clock = DiagDir::ANTI_UP;
            next_row_clock = row - 1;
            next_col_clock = col + 1;

            new_dir_counterclock = DiagDir::ANTI_DOWN;
            next_row_counter = row + 1;
            next_col_counter = col - 1;
            break;

        case DiagDir::MAIN_DOWN:
            next_row = row + 1;
            next_col = col + 1;

            new_dir_clock = DiagDir::ANTI_DOWN;
            next_row_clock = row + 1;
            next_col_clock = col - 1;

            new_dir_counterclock = DiagDir::ANTI_UP;
            next_row_counter = row - 1;
            next_col_counter = col + 1;
            break;

        case DiagDir::ANTI_UP:
            next_row = row - 1;
            next_col = col + 1;

            new_dir_clock = DiagDir::MAIN_DOWN;
            next_row_clock = row + 1;
            next_col_clock = col + 1;

            new_dir_counterclock = DiagDir::MAIN_UP;
            next_row_counter = row - 1;
            next_col_counter = col - 1;
            break;

        case DiagDir::ANTI_DOWN:
            next_row = row + 1;
            next_col = col - 1;

            new_dir_clock = DiagDir::MAIN_UP;
            next_row_clock = row - 1;
            next_col_clock = col - 1;

            new_dir_counterclock = DiagDir::MAIN_DOWN;
            next_row_counter = row + 1;
            next_col_counter = col + 1;
            break;

        default:
            break;
        }

        int curr_len = 1;
        int preceding_value = grid[row][col];

        // continue in same direction
        int straight_len = gen_v_diag(next_row, next_col, dir, has_turned,
                                      preceding_value, grid, dp);
        curr_len = max(curr_len, straight_len + 1);

        if (!has_turned) {
            // turn 90 clockwise
            int clock_len =
                gen_v_diag(next_row_clock, next_col_clock, new_dir_clock, true,
                           preceding_value, grid, dp);
            curr_len = max(curr_len, clock_len + 1);

            // // turn 90 counterclockwise
            // int counter_len = gen_v_diag(next_row_counter, next_col_counter,
            //                              new_dir_counterclock, true,
            //                              preceding_value, grid, dp);
            // curr_len = max(curr_len, counter_len + 1);
        }

        // memoize
        dp[row][col][static_cast<int>(dir)][has_turned] = curr_len;
        return curr_len;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int max_len = 0;

        // memoization vector
        vector<vector<vector<vector<int>>>> dp(
            rows,
            vector<vector<vector<int>>>(
                cols, vector<vector<int>>(NUM_DIRECTIONS, vector<int>(2, -1))));

        // populate it
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != 1) {
                    continue;
                }
                bool has_taken_turn = false;
                int preceding_value = -1; // flags the start, which is valid;
                max_len = max(max_len, gen_v_diag(i, j, DiagDir::MAIN_UP, has_taken_turn, preceding_value, grid, dp));
                max_len = max(max_len, gen_v_diag(i, j, DiagDir::MAIN_DOWN, has_taken_turn, preceding_value, grid, dp));
                max_len = max(max_len, gen_v_diag(i, j, DiagDir::ANTI_UP, has_taken_turn, preceding_value, grid, dp));
                max_len = max(max_len, gen_v_diag(i, j, DiagDir::ANTI_DOWN, has_taken_turn, preceding_value, grid, dp));
            }
        }
        return max_len;
    }
};