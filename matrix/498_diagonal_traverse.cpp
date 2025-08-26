/*
We can model this problem by defining a set of collision behaviors.
Which?

    1. When you collide with the ceiling going up. You go to the right and then down.

    2. When you collide with the left going down. You go down and then upwards.

    3. When you collide to the right going up. You go down and then downwards.

    4. When you collide with the bottom going down. You go to the right and then upwards.

Can we just implement these behaviors? Are there any effiency concerns? It will be O(n*m), we have to traverse the matrix.

We need to make sure the output follows a construction pattern, just like a heap.

Never underestimate the logical condition for the while.

I got tricked between && and ||. Rookie mistake.
*/


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool goingUp = true;
        vector<int> output;
        int n = mat.size();
        int m = mat[0].size();
        int i = 0;
        int j = 0;

        // Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
        // Output: [1,2,4,7,5,3,6,8,9]
        while (i != n-1 || j != m-1) {      // 2, 2, false
            output.push_back(mat[i][j]);    // {1, 2, 4, 7, 5, 3, 6, 8}
            if (goingUp) {
                if (j == m-1) {         // hit the right  
                    i += 1;                 // go down
                    goingUp = false;
                } else if (i == 0) {    // hit the ceiling
                    j += 1;                 // go right
                    goingUp = false;
                } else {                // didn't hit anything, proceed
                    i -= 1;
                    j += 1;
                }
            } else {
                if (i == n-1) {         // hit the floor 
                    j += 1;
                    goingUp = true;
                } else if (j == 0) {    // hit the left
                    i += 1;
                    goingUp = true;
                } else {
                    i += 1;
                    j -= 1;
                }
            }
        }
        output.push_back(mat[i][j]);     // add last diagonal member // {1, 2, 4, 7, 5, 3, 6, 8, 9}
        return output;
    }
};