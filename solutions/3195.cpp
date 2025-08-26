class Solution {
public:
    /*
        Doesn't change worst-case complexity.
        But it is objectively better as in faster;
        Is it? Well, not necessarily.
        Suppose there's a lonely 1 in the middle.
        Then we would do a lot of redundant calculation.
        Anyway, that would still be 4*n/2*m/2 which is what we were
        afraid to begin with.
        Long live The King™. Check out TempleOS™.
        Ok. Done, but this is quite imbecile-istic.
    */
    int minimumArea(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size(); // do we have edge cases? no: 1 <=
                                   // grid.length, grid[i].length <= 1000
        int upmost;
        int leftmost;
        int rightmost;
        int downmost;

        // find top boundary
        bool found = false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    upmost = i;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        // find left boundary
        found = false;
        for (int j = 0; j < cols; j++) {
            for (int i = upmost; i < rows; i++) {
                if (grid[i][j] == 1) {
                    leftmost = j;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        // find right boundary
        found = false;
        for (int j = cols - 1; j >= leftmost; j--) {
            for (int i = rows - 1; i >= upmost; i--) {
                if (grid[i][j] == 1) {
                    rightmost = j;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        // find bottom boundary
        found = false;
        for (int i = rows - 1; i >= upmost; i--) {
            for (int j = rightmost; j >= leftmost; j--) {
                if (grid[i][j] == 1) {
                    downmost = i;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        // calculate area
        int width = rightmost - leftmost + 1;
        int height = downmost - upmost + 1;
        return width * height;
    }

    /* This is good enough. But what if we have a huge matrix? */
    // int minimumArea(vector<vector<int>>& grid) {

    //     int rows = grid.size();
    //     int cols = grid[0].size(); // do we have edge cases? no: 1 <=
    //                                // grid.length, grid[i].length <= 1000

    //     // idxs of boundary 1s
    //     int upmost = -1;
    //     int leftmost = cols - 1;
    //     int rightmost = 0;
    //     int downmost = 0;

    //     // find those idxes
    //     for (int i = 0; i < rows; i++) {
    //         for (int j = 0; j < cols; j++) {
    //             if (grid[i][j] == 0) {
    //                 continue;
    //             } // skip 0s

    //             // update upmost
    //             if (upmost == -1) {
    //                 upmost = i;
    //             }

    //             // update leftmost
    //             if (j < leftmost) {
    //                 leftmost = j;
    //             }

    //             // update rightmost
    //             if (j > rightmost) {
    //                 rightmost = j;
    //             }

    //             downmost = i;
    //         }
    //     }

    //     // calculate area
    //     int width = rightmost - leftmost + 1;
    //     int height = downmost - upmost + 1;
    //     return width * height;
    // }
};