class Solution {
public:
    // My first and beautiful solution.
    // std::unordered_map<std::string, int> roman_to_integer = {
    //     {"I", 1},   {"IV", 4},   {"V", 5},   {"IX", 9},  {"X", 10},
    //     {"XL", 40}, {"L", 50},   {"XC", 90}, {"C", 100}, {"CD", 400},
    //     {"D", 500}, {"CM", 900}, {"M", 1000}};

    // Remember to test, kids.
    // M C M X C I V
    // 0 1 2 3 4 5 6
    // 4 + 90 + 900 + 1000
    // int romanToInt(string s) {
    //     int i = s.size() - 1;
    //     int sum = 0;
    //     while (i >= 0) { // watch out for i=-1 -> s[i]

    //         std::string curr = s.substr(i, 1);
    //         if (i == 0) {
    //             sum += roman_to_integer[curr];
    //             break;
    //         } else {
    //             std::string curr_with_lookahead = s.substr(i - 1, 2);
    //             if (roman_to_integer.find(curr_with_lookahead) !=
    //                 roman_to_integer.end()) {
    //                 sum += roman_to_integer[curr_with_lookahead];
    //                 i -= 2;
    //             } else {
    //                 sum += roman_to_integer[curr];
    //                 i -= 1;
    //             }
    //         }
    //     }
    //     return sum;
    // }

    // My second and whispered solution.
    std::unordered_map<char, int> roman_to_integer = {
        {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}};

    // Remember to test, kids.
    // M C M X C I V
    // 0 1 2 3 4 5 6
    // 4 + 90 + 900 + 1000
    int romanToInt(string s) {
        int i = 0;
        int sum = 0;
        while (i < s.size()) { // watch out for i=-1 -> s[i]

            int curr = roman_to_integer[s[i]];
            if (i + 1 < s.size()) {
                int lookahead = roman_to_integer[s[i + 1]];
                if (curr < lookahead) {
                    sum += lookahead - curr;
                    i += 2;
                    continue;
                }
            }
            sum += curr;
            i++;
        }
        return sum;
    }
};