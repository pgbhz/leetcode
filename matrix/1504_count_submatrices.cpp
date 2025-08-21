class Solution {
public:
    int numSubmat(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int totalSubmatrices = 0;
        vector<vector<int>> leftOnes(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (j == 0) {
                    leftOnes[i][j] = matrix[i][j];
                } else {
                    leftOnes[i][j] = (matrix[i][j] == 0) ? 0 : leftOnes[i][j - 1] + 1;
                }
                int minWidth = leftOnes[i][j];
                for (int k = i; k >= 0; --k) {
                    minWidth = min(minWidth, leftOnes[k][j]);
                    if (minWidth == 0) {
                        break;
                    }
                    totalSubmatrices += minWidth;
                }
            }
        }
        return totalSubmatrices;
    }
};