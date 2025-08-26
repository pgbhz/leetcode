/*
Rotations mentioned.
Probably a hash map for storing symmetries followed by a reversal.
Rotation = Reversal + Process each char and stop early

ARE WE ALLOWED TO CAST FROM INT TO STRING? YES PLEASE

*/

class Solution {
public:
    bool confusingNumber(int n) {
        std::string number = std::to_string(n);

        std::string reversed = "";
        int i = number.size() - 1;
        while (i >= 0) {
            reversed.push_back(number[i]);
            i--;
        }

        std::unordered_map<char, char> symmetries = {
            {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        i = 0;
        while (i < number.size()) {
            if (symmetries.find(reversed[i]) == symmetries.end()) {
                return false;
            }
            reversed[i] = symmetries[reversed[i]];
            i++;
        }
        int rotated = std::stoi(reversed);
        return n != rotated;
    }
};

// dont underestimate the problem, friend.
//     if (n == 0) {
//         return false;
//     }
//     std::string number = std::to_string(n);
//     if (number.size() == 1) {
//         switch (n) {
//             case 0: return false;
//             case 1: return false;
//             case 2: return false;
//             case 3: return false;
//             case 4: return false;
//             case 5: return false;
//             case 7: return false;
//             case 8: return false;
//             default: return true;
//         }
//     }
//     bool is_all_equal = true;
//     int i = 0;
//     if (number[i] == '2' || number[i] == '3' || number[i] == '4' ||
//         number[i] == '5' || number[i] == '7') {
//         return false;
//     }
//     i = 1;
//     while (i < number.size()) {
//         if (number[i] != number[i-1]) {
//             is_all_equal = false;
//         }
//         if (number[i] == '2' || number[i] == '3' || number[i] == '4' ||
//             number[i] == '5' || number[i] == '7') {
//             return false;
//         }
//         i++;
//     }
//     return !is_all_equal;
// }