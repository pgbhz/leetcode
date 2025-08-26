/*
Maximum area of longest diagonal rectangle.
    What is a diagonal rectangle??? Aren't they all?
    We're given a matrix. But it is easier to see it as a vector of pairs.
    {(length, width), (length, width), ...}
    We want the area of the rectangle with the longest diagonal.

    a a
    a a 
    a a         what is the size of this diagonal? 2?
    a a
    a a

    a a a a
    a a a a     same here?

    or are we considering just the geometric calculation?
    which is......... sqrt(l*l + w*w)

    is there any tricks to this or is it just easy?
    won't we just linear scan through it?

    this is CPPPPPPPPPP !!!!!!!!!!!!!!!!
    don't put the result of a sqrt into an integer, you dummie.

    and NEVER, underestimate the problem.
*/

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        float max_diagonal = -1;  // 10.44
        int max_area = -1;      // 30
        float max_area_diag = -1;

        // [[10,3],[5,9],[8,3]]
        for (auto dim : dimensions) {
            int length = dim[0];    // 5
            int width = dim[1];     // 9
            float diagonal = std::sqrt((length*length + width*width));    // sqrt ( 25 + 81 ) = 10.44
            int area = width*length;

            if (diagonal >= max_diagonal) {     
                if (diagonal > max_diagonal) {
                    max_area = area;
                    max_diagonal = diagonal;
                } else {
                    if (area > max_area) {
                        max_area = area;
                    }
                }
            }
        }
        return max_area;
    }
};