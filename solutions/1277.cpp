/*
First, we implement brute-force.
Then, DP.
*/

class Solution {
public:
    // int countSquares(vector<vector<int>>& matrix) {
    //     int squares = 0;
    //     int rows = matrix.size();
    //     int cols = matrix[0].size();
    //     for (int i = 0; i < rows; i++) {
    //         for (int j = 0; j < cols; j++) {
    //             if (!matrix[i][j] == 1) {
    //                 continue;
    //             }
    //             int size = 1;
    //             int m = i;
    //             int n = j;
    //             while (m < rows && n < cols) {
    //                 bool is_square = true;
    //                 for (int p = i; p <= m; p++) {
    //                     for (int q = j; q <= n; q++) {
    //                         if (matrix[p][q] == 0) {
    //                             is_square = false;
    //                         }
    //                     }
    //                 }
    //                 if (is_square) {
    //                     squares += 1;
    //                     m += 1;
    //                     n += 1;
    //                 } else {
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     return squares;
    // }

    int countSquares(vector<vector<int>>& matrix) {
        int squares = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    continue;
                }
                dp[i + 1][j + 1] =
                    min({dp[i][j + 1], dp[i + 1][j], dp[i][j]}) + 1;
                squares += dp[i + 1][j + 1];
            }
        }
        return squares;
    }

};