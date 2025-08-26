/*
Keep in mind to refrain from hitting the submit button like a crazy person.
You will submit when you are sure that it will work.
You will improve on your past self.

First thing that came to my mind was a DSA approach. Flood filling this
amorphous shape. But no. Why? Because we need to find 3 non-overlapping
rectangles. 3. What comes to mind when thinking about this? First, some sort of
tree. In this tree, each node is a configuration of three rectangles. But, as
there are many ways to change from one configuration to another, each level
grows absurdly. How to map this geometrical problem to one of the well known
paradigms? Divide and conquer? Backtracking? Dynamic programming? Graph
traversal? I'm hitting a hint. Keep in mind that we want to minimize this.
Linear programming sort of thing.
    - All the 1s in the grid must lie inside these rectangles.
    - We can cover 0s with them.
    - There are at least three 1s in the grid.
Two hours later, back we are.

Hint 1
Tapping the first hint. We should begin considering two rectangles. What insight
does this provide? What are the rules for deploying these rectangles? We start
with a first one, cover until some threshold and then deploy the other? How to
choose between which we maintain fixed? Sounds esoteric. Hard for a reason. How
to approach this problem is uncharted territory to me. Im hitting hint number
two.

Hint 2
It recommends some sort of brute-force approach. Consider all possible vertical
and horizontal splits.

Hint 3
Recommends covering one rectangle, then splitting that into two and three.
So basically we proceed like yesterday's question, find the big rectangle that
cover all ones. Then we split that into two rectangles. How? We set a
middlepoint variable I guess. Then, we do that again. It is not clear how to do
that programatically. I can start reimplementing yesterday's logic.

Hitting the editorial now.
We can divide the grid into three non-overlapping sections and treat each
section as a separate instance of the problem of finding the min area to cover
all ones. Ok.

But how do we choose these sections?
If we set the first section, the second and third are automatically set.
    If we grow this first section rightwards and downwards, the second and third
automatically follows. Is it sufficient to test all possible first section
growths?

        I think we need to test all the first possible section growths, then all
possible second section growths. But this is only my intuition. We should also
keep track of the sections boundaries, so we don't repeat configurations.

        A section can grow from 1x1 to all rows except last, or all columns
except last. I think this is a sufficient model to start implementing.

How do we handle from cutting inside the first vertical split and the second?
Does it matter?

    -------------------
    |                  |
    |                  |
    -------------------
    |         |        |
    |         |        |
    |         |        |
    --------------------

        vs.

    -------------------
    |         |        |
    |         |        |
    |         |        |
    -------------------
    |                  |
    |                  |
    --------------------

    Lessons learned.
        The thought above is key.
        Geometric problems can be about enumerating cases.
*/

// My honest human ritalin-powered effort
// class Solution {
// public:
//     int min_cover_square_area(std::pair<int, int> top_left,
//                               std::pair<int, int> bottom_right,
//                               vector<vector<int>>& grid) {
//         int min_i = top_left.first;
//         int max_i = bottom_right.first;
//         int min_j = top_left.second;
//         int max_j = bottom_right.second;

//         for (int i = top_left.first; i <= bottom_right.first; i++) {
//             for (int j = top_left.second; j <= bottom_right.second; j++) {
//                 if (grid[i][j] == 0) {
//                     continue;
//                 }
//                 min_i = std::min(min_i, i);
//                 min_j = std::min(min_j, j);
//                 max_i = std::max(max_i, i);
//                 max_j = std::max(max_j, j);
//             }
//         }
//         return (max_i - min_i + 1) * (max_j - min_j + 1);
//     }

//     int minimumSum(vector<vector<int>>& grid) {

//         int min_sum = std::numeric_limits<int>::max();

//         for (int i = 1; i < grid.size() - 1; i++) {
//             for (int j = 1; j < grid[0].size() - 1; j++) {

//                 int curr_sum = 0;

//                 // add the min square area for first section
//                 curr_sum +=
//                     min_cover_square_area({0, 0}, {(i - 1), (j - 1)}, grid);

//                 // add the min square area for second section
//                 curr_sum += min_cover_square_area(
//                     {0, j}, {(i - 1), (grid[0].size() - 1)}, grid);

//                 // add the min square area for third section
//                 curr_sum += min_cover_square_area(
//                     {i, 0}, {(grid.size() - 1), (grid[0].size() - 1)}, grid);

//                 min_sum = std::min(min_sum, curr_sum);
//             }
//         }

//         return min_sum;
//     }
// };

// ai grinded induced sloppery slop
class Solution {
private:
    int solve(const std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int min_sum = std::numeric_limits<int>::max();

        // three vertically split rectangles
        for (int i = 0; i < rows - 1; ++i) {
            for (int j = i + 1; j < rows - 1; ++j) {
                int area1 = min_cover_square_area({0, 0}, {i, cols - 1}, grid);
                int area2 = min_cover_square_area({i + 1, 0}, {j, cols - 1}, grid);
                int area3 = min_cover_square_area({j + 1, 0}, {rows - 1, cols - 1}, grid);
                min_sum = std::min(min_sum, area1 + area2 + area3);
            }
        }

        // top rectangle and the rest split into two horizontal rectangles
        for (int i = 0; i < rows - 1; ++i) {
            // vertical split
            int area1 = min_cover_square_area({0, 0}, {i, cols - 1}, grid);
            
            // horizontal split
            for (int j = 0; j < cols - 1; ++j) {
                int area2 = min_cover_square_area({i + 1, 0}, {rows - 1, j}, grid);
                int area3 = min_cover_square_area({i + 1, j + 1}, {rows - 1, cols - 1}, grid);
                min_sum = std::min(min_sum, area1 + area2 + area3);
            }
        }
        
        // top section split into two horizontal rectangles, and a bottom rectangle
        for (int i = 0; i < rows - 1; ++i) {
            // vertical split
            int area1 = min_cover_square_area({i + 1, 0}, {rows - 1, cols - 1}, grid);
            
            // horizontal split
            for (int j = 0; j < cols - 1; ++j) {
                int area2 = min_cover_square_area({0, 0}, {i, j}, grid);
                int area3 = min_cover_square_area({0, j + 1}, {i, cols - 1}, grid);
                min_sum = std::min(min_sum, area1 + area2 + area3);
            }
        }
        
        return min_sum;
    }

public:
    int minimumSum(std::vector<std::vector<int>>& grid) {
        int min_sum = solve(grid);

        // transpose grid to handle horizontal splits
        int rows = grid.size();
        int cols = grid[0].size();
        std::vector<std::vector<int>> transposed_grid(cols, std::vector<int>(rows));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                transposed_grid[j][i] = grid[i][j];
            }
        }

        min_sum = std::min(min_sum, solve(transposed_grid));

        return min_sum;
    }

private:
    int min_cover_square_area(const std::pair<int, int> top_left,
                              const std::pair<int, int> bottom_right,
                              const std::vector<std::vector<int>>& grid) {
        int min_i = grid.size(), max_i = -1;
        int min_j = grid[0].size(), max_j = -1;

        for (int i = top_left.first; i <= bottom_right.first; ++i) {
            for (int j = top_left.second; j <= bottom_right.second; ++j) {
                if (grid[i][j] == 1) {
                    min_i = std::min(min_i, i);
                    max_i = std::max(max_i, i);
                    min_j = std::min(min_j, j);
                    max_j = std::max(max_j, j);
                }
            }
        }

        if (max_i == -1) {
            return 0;
        }
        return (max_i - min_i + 1) * (max_j - min_j + 1);
    }
};