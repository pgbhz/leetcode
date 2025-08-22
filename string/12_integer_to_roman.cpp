class Solution {
public:
    /*
    Input: num = 3749
    Output: "MMMDCCXLIX"
    */
    string intToRoman(int num) {
        std::vector<std::string> roman;
        return recursively_roman(num, roman);
    }

    bool startsWithNineOrFour(int number) {
        if (number == 0) {
            return false;
        }

        while (number >= 10) {
            number /= 10;
        }

        return (number == 9 || number == 4);
    }

    string recursively_roman(int num, std::vector<string> roman) {
            if (num == 0) {
                std::string result = "";
                for (auto s : roman) {
                    result += s;
                }
                return result;
            }

            if (startsWithNineOrFour(num)) {
                if (num >= 900) {
                    num -= 900;
                    roman.push_back("CM");
                } else if (num >= 400) {
                    num -= 400;
                    roman.push_back("CD");
                } else if (num >= 90) {
                    num -= 90;
                    roman.push_back("XC");
                } else if (num >= 40) {
                    num -= 40;
                    roman.push_back("XL");
                } else if (num >= 9) {
                    num -= 9;
                    roman.push_back("IX");
                } else {
                    num -= 4;
                    roman.push_back("IV");
                }
            } else {
                if (num >= 1000) {
                    num -= 1000;
                    roman.push_back("M");
                } else if (num >= 500) {
                    num -= 500;
                    roman.push_back("D");
                } else if (num >= 100) {
                    num -= 100;
                    roman.push_back("C");
                } else if (num >= 50) {
                    num -= 50;
                    roman.push_back("L");
                } else if (num >= 10) {
                    num -= 10;
                    roman.push_back("X");
                } else if (num >= 5) {
                    num -= 5;
                    roman.push_back("V");
                } else {
                    num -= 1;
                    roman.push_back("I");
                }
            }
            
            return recursively_roman(num, roman);
        }
};